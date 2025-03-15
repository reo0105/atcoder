#pragma GCC optimize("O3", "unroll-loops", "omit-frame-pointer", "inline")
#pragma GCC option("arch=native", "tune=native", "no-zero-upper") // Enable AVX
#pragma GCC target("avx2")
#include <x86intrin.h>
#include <string>
#include <sstream>
#include <random>
#include <iostream>
#include <queue>
#include <chrono>
#include <bitset>
#include <array>
#include <algorithm>
#include <assert.h>
#include <unordered_set>
using std::cerr;
using std::cin;
using std::cout;
using std::endl;

std::mt19937 mt(0);
uint64_t m = mt();
uint64_t xorshift()
{
    m ^= m >> 9;
    m ^= m << 7;
    return m;
}

// 時間を管理するクラス
class TimeKeeper
{
private:
    std::chrono::high_resolution_clock::time_point start_time_;
    int64_t time_threshold_;

public:
    // 時間制限をミリ秒単位で指定してインスタンスをつくる。
    TimeKeeper(const int64_t &time_threshold)
        : start_time_(std::chrono::high_resolution_clock::now()),
          time_threshold_(time_threshold)
    {
    }

    // インスタンス生成した時から指定した時間制限を超過したか判定する。
    bool isTimeOver() const
    {
        auto diff = std::chrono::high_resolution_clock::now() - this->start_time_;
        return std::chrono::duration_cast<std::chrono::milliseconds>(diff).count() >= time_threshold_;
    }
};

using ScoreType = int64_t;                    // ゲームの評価スコアの型を決めておく。
constexpr const ScoreType INF = 1000000000LL; // あり得ないぐらい大きなスコアの例を用意しておく

constexpr const int N = 100;
constexpr const int K = 8;
constexpr const int H = 48;
constexpr const int W = 48;
constexpr const int T = 2500;

constexpr const int dx[4] = {1, -1, 0, 0}; // 右、左、下、上への移動方向のx成分
constexpr const int dy[4] = {0, 0, 1, -1}; // 右、左、下、上への移動方向のy成分
constexpr const char *STRS = "RLDU";
constexpr const int BEAM_WIDTH = 3;
constexpr const int BEAM_WIDTH_TIMES_ACTIONS = BEAM_WIDTH * 4;
constexpr const int BEAM_DEPTH = T;

namespace zobrist_hash
{
    // 壁の場所は固定なのでhash管理しない
    uint64_t visiteds[K][H][W] = {}; // 数字そのままで入れられるように1足す
    uint64_t characters[K][H][W] = {};
    void init()
    {
        for (int i = 0; i < K; i++)
            for (int y = 0; y < H; y++)
                for (int x = 0; x < W; x++)
                {
                    visiteds[i][y][x] = xorshift();
                    characters[i][y][x] = xorshift();
                }
    }

}

namespace single_bitset
{
    std::bitset<H * W> initLeftMask()
    {
        std::bitset<H *W> mask = std::bitset<H * W>();
        for (int y = 0; y < H; ++y)
        {
            mask |= (std::bitset<H * W>(1) << (y * W));
        }
        mask = ~mask;
        return mask;
    }
    std::bitset<H * W> initRightMask()
    {
        std::bitset<H *W> mask = std::bitset<H * W>();
        for (int y = 0; y < H; ++y)
        {
            mask |= (std::bitset<H * W>(1) << (y * W + W - 1));
        }
        mask = ~mask;
        return mask;
    }

    std::bitset<H *W> left_mask = initLeftMask();
    std::bitset<H *W> right_mask = initRightMask();

    // 1個のbitsetでH*Wの二次元配列を表現する
    class Mat
    {
    private:
        std::bitset<H * W> bits_{};

        Mat up_mat() const
        {
            Mat ret_mat = *this;
            ret_mat.bits_ >>= W;

            return ret_mat;
        }
        Mat down_mat() const
        {
            Mat ret_mat = *this;
            ret_mat.bits_ <<= W;

            return ret_mat;
        }
        Mat left_mat() const
        {
            Mat ret_mat = *this;
            ret_mat.bits_ |= (ret_mat.bits_ & left_mask) >> 1;

            return ret_mat;
        }
        Mat right_mat() const
        {
            Mat ret_mat = *this;
            ret_mat.bits_ |= (ret_mat.bits_ & right_mask) << 1;
            return ret_mat;
        }

    public:
        Mat(){};
        Mat(const std::bitset<H * W> &mat) : bits_(mat){};

        // 指定位置にbitがあるか
        bool get(int y, int x) const
        {
            return bits_[y * W + x];
        }

        // 指定位置にbitをたてる
        void set(int y, int x)
        {
            bits_.set(y * W + x);
        }
        // 指定位置のbitを消す
        void del(int y, int x)
        {
            bits_.reset(y * W + x);
        }
        // 全bitを4方向に広げる
        void expand()
        {
            Mat up = up_mat();
            Mat down = down_mat();
            Mat left = left_mat();
            Mat right = right_mat();
            this->bits_ |= up.bits_;
            this->bits_ |= down.bits_;
            this->bits_ |= left.bits_;
            this->bits_ |= right.bits_;
        }

        void set_not()
        {
            this->bits_ = ~this->bits_;
        }

        void oreq(const Mat &mat)
        {

            this->bits_ |= mat.bits_;
        }

        // *this&=~mat // not演算と分けると効率が悪いので1演算にする
        void andeq_not(const Mat &mat)
        {

            this->bits_ &= ~mat.bits_;
        }

        // *this == mat
        bool is_equal(const Mat &mat) const
        {
            return this->bits_ == mat.bits_;
        }
        int and_cnt(const Mat &mat) const
        {
            return (this->bits_ & mat.bits_).count();
        }
        // *thisとmatで重複して立っているbitが1つでもあるか
        bool is_any_equal(const Mat &mat) const
        {
            return (this->bits_ & mat.bits_).any();
        }
        bool is_any_equal_not(const Mat &mat) const
        {
            return (this->bits_ & ~mat.bits_).any();
        }
        int64_t count() const
        {
            return this->bits_.count();
        }
        void printErr() const
        {
            using namespace std;
            for (int y = 0; y < H; y++)
            {
                for (int x = 0; x < W; x++)
                {
                    cerr << get(y, x);
                }
                cerr << endl;
            }
            for (int x = 0; x < W; x++)
            {
                cerr << "-";
            }
            cerr << endl;
            cerr << endl;
        }
    };
}
using single_bitset::Mat;

struct AllActions
{
    std::bitset<T * 2> data_;
    inline AllActions() = default;
    // turnターンでの行動をビットボードで表現する。
    // actionは0~3の範囲の値をとるため、1ターンあたり2bitの情報が必要になる。
    // data_のturn*2～tur*2+1の範囲の2ビットを使って2進数でactionの情報を保持することにする。
    // action & 1は actionの0ビット目の情報を、
    // action >> 1は actionの1ビット目の情報を
    // 取得することと等しい
    inline void Set(const int &turn, const int &action)
    {
        data_[turn * 2] = action & 1;
        data_[turn * 2 + 1] = action >> 1;
    }
    inline void Print() const
    {
        for (int i = 0; i < T; i++)
        {
            std::cout << STRS[(int)data_[i * 2 + 1] << 1 | (int)data_[i * 2]];
        }
        std::cout << std::endl;
    }
    inline void ePrint(int t = T) const
    {
        for (int i = 0; i < t; i++)
        {
            std::cerr << STRS[(int)data_[i * 2 + 1] << 1 | (int)data_[i * 2]];
        }
        std::cerr << std::endl;
    }
};

// 座標を保持する
struct Coord
{
    int y_;
    int x_;
    Coord(const int y = 0, const int x = 0) : y_(y), x_(x) {}
};

class Board
{
public:
    int id_ = 0;
    Mat walls_{};
    Mat traps_{};
    Mat coins_{};
    Coord character_{};
    Board() {}
};

namespace global
{

    Board boards[N]{};
    Board selected_boards[K]{};

    // 入力を読んでグローバル変数に格納する
    void readInput()
    {
        std::string buffer;             // 1行ずつ読み込むバッファ
        std::getline(std::cin, buffer); // Nなどの定数は不要なので無視
        for (int i = 0; i < N; i++)
        {
            boards[i].id_ = i;
            std::cin >> buffer;         // 1行目は壁だけなので無視
            for (int y = 0; y < H; y++) // H=48にしてる
            {
                std::cin >> buffer;
                for (int x = 0; x < W; x++) // W=48にしてる
                {
                    char c = buffer[x + 1]; // 1列目は壁だけなので無視
                    switch (c)
                    {
                    case '#':
                        boards[i].walls_.set(y, x);
                        break;
                    case 'x':
                        boards[i].traps_.set(y, x);
                        break;
                    case 'o':
                        boards[i].coins_.set(y, x);
                        break;
                    case '@':
                        boards[i].character_ = Coord(y, x);
                    default:
                        break;
                    }
                }
            }
            std::cin >> buffer; // 最終行は壁だけなので無視
        }
    }

    void eprintBoard(int i)
    {
        cerr << "board " << i << endl;
        const auto &board = boards[i];
        for (int y = 0; y < H; y++)
        {
            for (int x = 0; x < W; x++)
            {
                char c = 'o';
                if (board.walls_.get(y, x))
                {
                    c = '#';
                }
                else if (board.traps_.get(y, x))
                {
                    c = 'x';
                }
                else if (board.character_.y_ == y && board.character_.x_ == x)
                {
                    c = '@';
                }
                cerr << c;
            }
            cerr << endl;
        }
        cerr << "-------------------------------------" << endl;
        cerr << endl;
    }

    int getNearCoinN(int index, int range)
    {

        auto now = Mat();
        const auto &board = boards[index];
        now.set(board.character_.y_, board.character_.x_);
        int cnt = 0;
        for (int depth = 0; depth < range; ++depth)
        {
            auto next = now;
            next.expand();
            next.andeq_not(board.walls_);
            next.andeq_not(board.traps_);
            // next.printErr();
            if (next.is_equal(now))
            {
                break;
            }
            now = next;
        }

        return now.count();
        // return now.and_cnt(board.coins_);
    }

    void selectBoards()
    {
        std::vector<std::pair<int, int>> index_scores(N);
        for (int i = 0; i < N; i++)
        {
            int coin_count = boards[i].coins_.count();
            int trap_count = boards[i].traps_.count();
            int coin_cnts[6] = {};
            const auto &character = boards[i].character_;
            bool is_open = 1;
            for (int j = 1; j <= 5; j++)
            {
                coin_cnts[j] = getNearCoinN(i, j);
                // if (i == 97)
                // {
                //     cerr << "character y,x " << character.y_ << "," << character.x_ << endl;
                //     cerr << "coin_cnts " << j << " " << coin_cnts[j] << endl;
                // }
                if (j >= 2 && coin_cnts[j] == coin_cnts[j - 1])
                {
                    is_open = 0;
                    break;
                }
            }
            // is_open = (coin_cnts[1] >= 1);

            // if (trap_cnt1 >= 1)
            // {
            //     trap_cnt1 = 1;
            // }
            int gap_x = std::abs(0 - character.x_);
            int gap_y = std::abs(0 - character.y_);
            int gap = gap_x + gap_y;

            int range2 = 100;
            // int trap_cnt2 = getNearTrapN(i, range2);
            // int wall_cnt2 = getNearWallN(i, range2);
            // int coin_cnt2 = getNearCoinN(i, range2);

            // int score = (is_open * 2500 + coin_count) * 2500 - gap;
            int score = (is_open * 2500 + coin_count);
            // int score = (-trap_cnt1 * 10 + coin_count) * 10000 + coin_cnt2;
            // int score = coin_count;
            index_scores[i] = {score, i};
            // cerr << "coin_count " << coin_count << endl;
        }
        nth_element(index_scores.begin(), index_scores.begin() + K, index_scores.end(), std::greater<>());
        for (int i = 0; i < K; i++)
        {
            const auto board_id = index_scores[i].second;
            selected_boards[i] = boards[board_id];
        }

        // int M = K * 1.5;
        // nth_element(index_scores.begin(), index_scores.begin() + M, index_scores.end(), std::greater<>());
        // index_scores.resize(M);
        // int mean_y = 0;
        // int mean_x = 0;
        // for (const auto &index_score : index_scores)
        // {
        //     int i = index_score.second;
        //     const auto &character = boards[i].character_;
        //     mean_y += character.y_;
        //     mean_x += character.x_;
        // }
        // mean_y /= M;
        // mean_x /= M;
        // for (auto &index_score : index_scores)
        // {
        //     int i = index_score.second;
        //     int coin_count = boards[i].coins_.count();
        //     int trap_count = boards[i].traps_.count();
        //     int range1 = 1;
        //     int coin_cnt1 = getNearCoinN(i, range1);
        //     int is_open = coin_cnt1 >= 1;
        //     // if (trap_cnt1 >= 1)
        //     // {
        //     //     trap_cnt1 = 1;
        //     // }
        //     const auto &character = boards[i].character_;
        //     int gap_x = std::abs(mean_x - character.x_);
        //     int gap_y = std::abs(mean_y - character.y_);
        //     int gap = gap_x + gap_y;

        //     int range2 = 100;
        //     // int trap_cnt2 = getNearTrapN(i, range2);
        //     // int wall_cnt2 = getNearWallN(i, range2);
        //     int coin_cnt2 = getNearCoinN(i, range2);

        //     // int score = (is_open * 2500 + coin_count) * 2500 - gap;
        //     int score = (coin_count + coin_cnt2) - gap;
        //     ;
        //     // int score = (-trap_cnt1 * 10 + coin_count) * 10000 + coin_cnt2;
        //     // int score = coin_count;
        //     index_score.first = score;
        //     // cerr << "coin_count " << coin_count << endl;
        // }
        // nth_element(index_scores.begin(), index_scores.begin() + K, index_scores.end(), std::greater<>());

        // for (int i = 0; i < K; i++)
        // {
        //     const auto board_id = index_scores[i].second;
        //     selected_boards[i] = boards[board_id];
        // }
    }
    void printSelectedBoards()
    {
        for (int i = 0; i < K; i++)
        {
            cout << selected_boards[i].id_;
            if (i != K - 1)
            {
                cout << " ";
            }
        }
        cout << "\n";
    }

}

namespace legal
{
    int legal_actions[4] = {};
    int legal_size = 0;
}

class State
{
private:
    int ref_count_ = 0; // 参照カウンタ

    // zobrist_hash用
    void init_hash()
    {
        hash_ = 0;
        for (int i = 0; i < K; i++)
        {
            const auto &character = this->characters_[i];
            hash_ ^= zobrist_hash::characters[i][character.y_][character.x_];
            hash_ ^= zobrist_hash::visiteds[i][character.y_][character.x_];
        }
    }

public:
    ScoreType evaluated_score_ = 0; // 探索上で評価したスコア
    AllActions all_actions_{};
    unsigned short int game_score_ = 0;
    unsigned short int turn_ = 0;
    Mat visiteds_[K]{};
    Coord characters_[K]{};
    uint64_t hash_ = 0; // 同一盤面判定に使うハッシュ
    State() {}
    void initState()
    {
        for (int i = 0; i < K; i++)
        {
            const auto &character = global::selected_boards[i].character_;
            characters_[i] = Coord(character.y_, character.x_);
            visiteds_[i].set(character.y_, character.x_);

            visiteds_[i].oreq(global::selected_boards[i].traps_);
            visiteds_[i].oreq(global::selected_boards[i].walls_);
        }
        init_hash();
    }

    // ゲームの終了判定
    bool isDone() const
    {
        /*処理*/
        return turn_ == T;
    }

    // bit演算により、最も近いポイントのある床までの距離を計算する。
    int getDistanceToNearestPoint(int index)
    {

        auto now = Mat();
        now.set(this->characters_[index].y_, this->characters_[index].x_);
        for (int depth = 0;; ++depth)
        {
            if (now.is_any_equal_not(this->visiteds_[index]))
            {
                return depth;
            }

            auto next = now;
            next.expand();
            next.andeq_not(global::selected_boards[index].walls_);
            next.andeq_not(global::selected_boards[index].traps_);
            if (next.is_equal(now))
            {
                break;
            }
            now = next;
        }

        return H * W;
    }
    int getDistanceToNearestPointAll()
    {
        int sum = 0;
        for (int i = 0; i < K; i++)
        {
            sum += getDistanceToNearestPoint(i);
        }
        return sum;
    }

    // 探索用の盤面評価をする
    void evaluateScore()
    {
        // this->evaluated_score_ = this->game_score_ * H * W * K - getDistanceToNearestPointAll();
        this->evaluated_score_ = game_score_;
        // this->evaluated_score_ = game_score_ * 10 + mt() % (10);
    }

    // 指定したactionでゲームを1ターン進める
    void advance(const int action)
    {
        for (int i = 0; i < K; i++)
        {
            auto ty = characters_[i].y_ + dy[action];
            auto tx = characters_[i].x_ + dx[action];
            bool is_in = 0 <= ty && ty < H && 0 <= tx && tx < W;
            if (!is_in)
            {
                continue;
            }
            const auto &board = global::selected_boards[i];
            if (board.walls_.get(ty, tx))
                continue;

            // legalActionsで罠にかかる可能性をつぶしているので罠は無視
            if (board.coins_.get(ty, tx) && visiteds_[i].get(ty, tx) == 0)
            {
                // cerr << "i:" << i << " ++this->game_score_" << endl;
                ++this->game_score_;
                visiteds_[i].set(ty, tx);
                hash_ ^= zobrist_hash::visiteds[i][ty][tx]; // 訪問情報を追加
            }
            const auto &character = characters_[i];
            hash_ ^= zobrist_hash::characters[i][character.y_][character.x_]; // 現在のキャラクター位置情報を削除
            characters_[i].y_ = ty;
            characters_[i].x_ = tx;
            hash_ ^= zobrist_hash::characters[i][ty][tx]; // 移動先のキャラクター位置情報を追加
        }
        // cerr << "action:" << action << endl;
        this->all_actions_.Set(this->turn_, action);
        ++this->turn_;
    }

    // 現在の状況でプレイヤーが可能な行動を全て取得する
    void setLegalActions() const
    {
        legal::legal_size = 0;
        for (int action = 0; action < 4; action++)
        {
            bool is_trap = false;
            for (int i = 0; i < K; i++)
            {
                auto ty = this->characters_[i].y_ + dy[action];
                auto tx = this->characters_[i].x_ + dx[action];
                bool is_in = 0 <= ty && ty < H && 0 <= tx && tx < W;
                if (!is_in)
                {
                    continue;
                }
                const auto &board = global::selected_boards[i];
                if (board.traps_.get(ty, tx))
                {
                    is_trap = true;
                    break; // 本当は罠にかかっても合法手だが、罠にかかる分を探索に含めると処理が重くなるので暫定でスキップ
                }
            }
            if (is_trap)
            {
                continue;
            }
            legal::legal_actions[legal::legal_size] = action;
            ++legal::legal_size;
        }
    }

    // 必要に応じてアンコメント
    // 現在のゲーム状況を文字列にする
    std::string toString() const
    {
        cerr << "toString" << endl;
        std::stringstream ss;
        std::array<std::array<std::array<char, W>, H>, K> buffers{};

        for (int i = 0; i < K; i++)
        {
            const auto &state = global::selected_boards[i];
            auto &buffer = buffers[i];
            for (int y = 0; y < H; y++)
            {
                for (int x = 0; x < W; x++)
                {
                    char c = '.';
                    if (state.walls_.get(y, x))
                    {
                        assert(c == '.');
                        c = '#';
                    }
                    else if (state.coins_.get(y, x) && !this->visiteds_[i].get(y, x))
                    {
                        assert(c == '.');
                        c = 'o';
                    }
                    else if (this->characters_[i].y_ == y && this->characters_[i].x_ == x)
                    {
                        assert(c == '.');
                        c = '@';
                    }
                    else if (state.traps_.get(y, x))
                    {
                        assert(c == '.');
                        c = 'x';
                    }
                    buffer[y][x] = c;
                }
            }
        }
        ss << "score: " << this->evaluated_score_ << "\n";
        cerr << "toString score" << endl;
        {
            int i = 0;
            const auto &buffer = buffers[i];

            const auto &state = global::selected_boards[i];
            ss << "id:" << state.id_ << "\n";
            cerr << "toString id" << endl;
            ss << "legalActions:[";
            this->setLegalActions();
            cerr << "toString aft legal" << endl;
            assert(legal::legal_size > 0);
            for (int j = 0; j < legal::legal_size; j++)
            {
                auto action = legal::legal_actions[j];
                cerr << "toString STRS[" << action << "]" << endl;

                ss << STRS[action] << ",";
            }
            ss << "]\n";
            cerr << "toString legalActions" << endl;

            for (int y = 0; y < H; y++)
            {
                for (int x = 0; x < W; x++)
                {
                    ss << buffer[y][x];
                }
                ss << "\n";
            }
            for (int x = 0; x < W; x++)
            {
                ss << "-";
            }
        }

        ss << "\n";
        return ss.str();
    }

    // 参照カウントを初期化する
    void init()
    {
        ref_count_ = 1;
    }
    // 参照カウントをインクリメントする
    void addRef()
    {
        ++ref_count_;
    }
    // 参照カウントをデクリメントする。参照がなくなったら破棄する
    void release()
    {
        if (ref_count_ == 1)
        {
            delete (this);
        }
        else
        {
            --ref_count_;
        }
    }
};

// 探索時のソート用に評価を比較する
bool operator<(const State &state_1, const State &state_2)
{
    return state_1.evaluated_score_ < state_2.evaluated_score_;
}

// [どのゲームでも実装する] : 探索時のソート用に評価を比較する
bool operator>(const State &state_1, const State &state_2)
{
    return state_1.evaluated_score_ > state_2.evaluated_score_;
}

class StatePtr
{
public:
    State *state;
    StatePtr()
    {
        this->state = new State();
        this->state->init();
    }
    StatePtr(const State &state)
    {
        this->state = new State();
        *this->state = state;
        this->state->init();
    }
    StatePtr(const StatePtr &state_ptr)
    {
        this->state = state_ptr.state;
        this->state->addRef();
    }
    void operator=(const StatePtr &state_ptr)
    {
        this->state->release();
        this->state = state_ptr.state;
        this->state->addRef();
    }
    ~StatePtr()
    {
        this->state->release();
    }
};
bool operator<(const StatePtr &state_ptr1, const StatePtr &state_ptr2)
{
    return (*state_ptr1.state) < (*state_ptr2.state);
}
bool operator>(const StatePtr &state_ptr1, const StatePtr &state_ptr2)
{
    return (*state_ptr1.state) > (*state_ptr2.state);
}
using namespace std;

template <typename Key>
struct HashSet
{
    using u32 = uint32_t;
    using u64 = uint64_t;

    u32 cap, s;
    vector<Key> keys;
    vector<bool> flag;
    u64 r;
    u32 shift;

    void reallocate()
    {
        cap <<= 1;
        vector<Key> k(cap);
        vector<bool> f(cap);
        u32 sh = shift - 1;
        for (int i = 0; i < (int)flag.size(); i++)
        {
            if (flag[i])
            {
                u32 hash = (u64(keys[i]) * r) >> sh;
                while (f[hash])
                    hash = (hash + 1) & (cap - 1);
                k[hash] = keys[i];
                f[hash] = 1;
            }
        }
        keys.swap(k);
        flag.swap(f);
        --shift;
    }

    explicit HashSet()
        : cap(8),
          s(0),
          keys(cap),
          flag(cap),
          r(xorshift()),
          shift(64 - __lg(cap)) {}

    void set(const Key &i)
    {
        u32 hash = (u64(i) * r) >> shift;
        while (true)
        {
            if (!flag[hash])
            {
                if (s + s / 4 >= cap)
                {
                    reallocate();
                    (*this).set(i);
                    return;
                }
                keys[hash] = i;
                flag[hash] = 1;
                ++s;
                return;
            }
            if (keys[hash] == i)
                return;
            hash = (hash + 1) & (cap - 1);
        }
    }

    // exist -> return pointer of Val
    // not exist -> return nullptr
    const bool exist(const Key &i) const
    {
        u32 hash = (u64(i) * r) >> shift;
        while (true)
        {
            if (!flag[hash])
                return false;
            if (keys[hash] == i)
                return true;
            hash = (hash + 1) & (cap - 1);
        }
    }
};

// ビーム幅と深さを指定してビームサーチで行動を決定する
// 戻り値は問題固有の形にカスタマイズ
AllActions beamSearchAction(const State &state)
{
    // cerr << "beamSearchAction" << endl;
    std::vector<StatePtr> now_vec;
    now_vec.reserve(BEAM_WIDTH + 1);
    std::priority_queue<StatePtr, std::vector<StatePtr>, std::greater<StatePtr>> now_beam(std::greater<StatePtr>(), std::move(now_vec));
    // now_beam.reserve(BEAM_WIDTH_TIMES_ACTIONS);
    // now_beam.emplace_back(state);
    now_beam.emplace(state);
    // auto hash_check = std::unordered_set<uint64_t>();
    // auto hash_check = HashSet<uint64_t>();
    // std::priority_queue<StatePtr, std::vector<StatePtr>, std::greater<StatePtr>> next_beam; // ループ中で初期化しないほうが速い
    // std::vector<StatePtr> next_beam;
    // next_beam.reserve(BEAM_WIDTH_TIMES_ACTIONS);

    StatePtr now_state_ptr{};
    State next_state;
    for (int t = 0; t < BEAM_DEPTH; t++)
    {

        std::vector<StatePtr> next_vec;
        next_vec.reserve(BEAM_WIDTH + 1);
        std::priority_queue<StatePtr, std::vector<StatePtr>, std::greater<StatePtr>> next_beam(std::greater<StatePtr>(), std::move(next_vec));
        // next_beam = now_beam;
        // next_beam.clear();
        // cerr << "t:" << t << endl;
        for (int i = 0; i < BEAM_WIDTH; i++)
        // for (const StatePtr &now_state : now_beam)
        {

            if (now_beam.empty())
                break;
            now_state_ptr = now_beam.top();
            now_beam.pop();
            now_state_ptr.state->setLegalActions();
            for (int action_i = 0; action_i < legal::legal_size; action_i++)
            {
                // cerr << "debug_cnt:" << debug_cnt << endl;
                next_state = *now_state_ptr.state;

                next_state.advance(legal::legal_actions[action_i]);

                next_state.evaluateScore();
                if (next_beam.size() >= BEAM_WIDTH && next_beam.top().state->evaluated_score_ >= next_state.evaluated_score_)
                {
                    continue;
                }

                // if (t >= 1 && hash_check.exist(next_state.hash_))
                // {
                //     continue;
                // }
                // hash_check.set(next_state.hash_);
                // next_state.all_actions_.ePrint(next_state.turn_);

                // cerr << "\taction:" << action << endl;
                // cerr << "\tgame_score_:" << next_state.game_score_ << endl;
                // cerr << "\tevaluated_score_:" << next_state.evaluated_score_ << endl;
                next_beam.emplace(next_state);
                if (next_beam.size() > BEAM_WIDTH)
                {
                    next_beam.pop();
                }
            }
        }

        // // ビーム幅分だけ上位のデータを残す処理をする。
        // if (next_beam.size() > BEAM_WIDTH)
        // {
        //     // ビーム幅分だけ上位のデータを先頭に寄せる
        //     std::nth_element(next_beam.begin(), next_beam.begin() + BEAM_WIDTH, next_beam.end(), std::greater<>());
        //     // ビーム幅分だけデータを切り取る
        //     next_beam.resize(BEAM_WIDTH);
        // }

        // now_beam = next_beam;
        // now_beam.clear();
        // std::copy(next_beam.begin(), next_beam.end(), back_inserter(now_beam));
        std::swap(now_beam, next_beam);

        // cerr << "best_actions" << endl;
        // best_state.all_actions_.ePrint(beam_depth);
        // cerr << "evaluated_score_:" << best_state.evaluated_score_ << endl;

        // if (best_state.isDone())
        // {
        //     break;
        // }
    }
    State best_state;

    while (!now_beam.empty())
    {
        best_state = *now_beam.top().state;
        now_beam.pop();
    }

    // 最も良いstateを取り出す。
    // nth_elementで処理した場合、0番目が最大であることが保証されない。
    // for (const StatePtr &now_state_ptr : now_beam)
    // {
    //     if (now_state_ptr.state->evaluated_score_ > best_state.evaluated_score_)
    //     {
    //         best_state = *now_state_ptr.state;
    //     }
    // }
    // cerr << "evaluated_score_:" << best_state.evaluated_score_ << endl;
    // best_state.all_actions_.ePrint();
    // std::cerr << best_state.toString() << endl;
    return best_state.all_actions_;
}

int main()
{
    // std::cerr << "thunder err-------------" << std::endl;
    zobrist_hash::init(); // 必ず最初に呼び出す。
    global::readInput();
    // AllActions all_actions{};
    global::selectBoards();

    int i = 97;
    auto &board = global::boards[i];
    auto &character = board.character_;
    auto &walls = board.walls_;
    auto &traps = board.traps_;
    // traps.printErr();
    // Mat mat{};
    // mat.set(character.y_, character.x_);
    // mat.expand();
    // mat.andeq_not(traps);
    // mat.andeq_not(walls);
    // mat.printErr();

    State state{};
    state.initState();

    global::printSelectedBoards();
    // auto all_actions = beamSearchActionWithTimeThreshold(state, 100, 1);
    auto all_actions = beamSearchAction(state);
    all_actions.Print();

    return 0;
}