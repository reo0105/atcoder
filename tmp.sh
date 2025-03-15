#include <bits/stdc++.h>
using namespace std;

struct Coord {
    int y_;
    int x_;
    Coord(const int y = 0, const int x = 0) : y_(y), x_(x) {}
};

constexpr const int N = 100;
constexpr const int K = 8;
constexpr const int H = 50;
constexpr const int W = 50;
constexpr int END_TURN = 2500;

using ScoreType = int64_t;
constexpr const ScoreType INF = 1e18;

namespace multi_bitset
{
    class Mat
    {
    private:
        vector<bitset<W>> bits_;

        Mat up_mat() const
        {
            Mat ret_mat = *this;
            for (int y = 0; y < H-1; y++)
            {
                ret_mat.bits_[y] |= ret_mat.bits_[y+1];
            }
        }

    public:
        Mat() {};
        Mat(const vector<bitset<W>>& mat) : bits_(mat) {};

        bool get(int y, int x) const
        {
            return bits_[y][x];
        }


        void set(int y, int x)
        {
            bits_[y].set(x);
        }

        void del(int y, int x)
        {
            bits_[y].reset(x);
        }

    };
}

namespace zobrist_hash
{
    mt19937 mt_init_hash(0);
    uint64_t coints[K][H][W] = {};
    uint64_t character[K][H][W] = {};

    void init()
    {
        for (int k = 0; k < K; k++)
        {
            for (int y = 0; y < H; y++)
            {
                for (int x = 0; x < W; x++)
                {
                    coints[k][y][x] = mt_init_hash();
                    character[k][y][x] = mt_init_hash();
                }
            }
        }
    }
}

class MazeState {
    private:
        bool coins_[K][H][W] = { false };
        bool visited_[K][H][W] = { false };
        bool traps_[K][H][W] = { false };
        bool walls_[K][H][W] = { false };
        int turn_ = 0;

        static constexpr const int dx[4] = {1, -1, 0, 0};
        static constexpr const int dy[4] = {0, 0, 1, -1};

        void init_hash()
        {
            hash_ = 0;
            for (int i = 0; i < K; i++)
            {
                hash_ ^= zobrist_hash::character[i][character_[i].y_][character_[i].x_];

                for (int y = 0; y < H; y++)
                {
                    for (int x = 0; x < W; x++)
                    {
                        bool visited = this->visited_[i][y][x];
                        if (visited)
                        {
                            hash_ ^= zobrist_hash::coints[i][y][x];
                        }
                    }
                }

            }
        }

    public:
        Coord character_[K] = {};
        int game_score_ = 0;
        ScoreType evaluated_score_ = 0;
        int first_action_ = -1;
        vector<int> all_actions_;
        uint64_t hash_ = 0;             // 同一盤面判定に使うハッシュ


        MazeState() {}

        MazeState(vector<vector<string>> mp) {
            
            for (int i = 0; i < K; i++) {
                for (int j = 0; j < H; j++) {
                    for (int k = 0; k < W; k++) {
                        if (mp[i][j][k] == '@') {
                            character_[i] = Coord(j, k);
                            visited_[i][j][k] = true;
                        } else if (mp[i][j][k] == 'o') {
                            coins_[i][j][k] = true;
                        } else if (mp[i][j][k] == 'x') {
                            traps_[i][j][k] = true;
                        } else {
                            walls_[i][j][k] = true;
                        }
                    }
                }
            }
            init_hash();
            
        }

        bool isDone() const {
            return this->turn_ == END_TURN;
        }


        void advance(const int action) {

            for (int i = 0; i < K; i++) {
                int tx = this->character_[i].x_ + dx[action];
                int ty = this->character_[i].y_ + dy[action];
                if (!(ty >= 0 && ty < H && tx >= 0 && tx < W)) continue;;
                if (this->walls_[i][ty][tx]) continue;

                hash_ ^= zobrist_hash::character[i][character_[i].y_][character_[i].x_];
                this->character_[i].x_ = tx;
                this->character_[i].y_ = ty;
                hash_ ^= zobrist_hash::character[i][ty][tx];
                
                bool isVisited = this->visited_[i][this->character_[i].y_][this->character_[i].x_];
                if (!isVisited) {
                    this->game_score_++;
                    this->visited_[i][this->character_[i].y_][this->character_[i].x_] = true;
                    hash_ ^= zobrist_hash::coints[i][ty][tx];
                }
            }
            this->all_actions_.emplace_back(action);
            this->turn_++;
        }

        vector<int> legalActions() const {
            vector<int> actions;

            for (int action = 0; action < 4; action++) {
                int trap = 0;
                for (int i = 0; i < K; i++) {
                    int ty = this->character_[i].y_ + dy[action];
                    int tx = this->character_[i].x_ + dx[action];
                    if (!(ty >= 0 && ty < H && tx >= 0 && tx < W)) continue;;
                    if (this->traps_[i][ty][tx]) {
                        trap = 1;
                        break;
                    }
                }
                if (!trap) actions.emplace_back(action);
            }

            return actions;
        }

        // string toString() const {
        //     stringstream ss;
        //     ss << "turn:\t" << this->turn_ << "\n";
        //     ss << "score:\t" << this->game_score_ << "\n";

        //     for (int h = 0; h < H; h++) {
        //         for (int w = 0; w < W; w++) {
        //             if (this->character_.y_ == h && this->character_.x_ == w) {
        //                 ss << "@";
        //             } else if (this->points_[h][w] > 0) {
        //                 ss << points_[h][w];
        //             } else {
        //                 ss << ".";
        //             }
        //         }
        //         ss << "\n";
        //     }

        //     return ss.str();
        // }

        void evaluateScore() {
            this->evaluated_score_ = this->game_score_;
        }
};


class TimeKeeper {
    private:
        chrono::high_resolution_clock::time_point start_time_;
        int64_t time_threshold_;

    public:
        TimeKeeper(const int64_t& time_threhshold) : start_time_(chrono::high_resolution_clock::now()), time_threshold_(time_threhshold) {}

        bool isTimeOver() const {
            using chrono::duration_cast;
            using chrono::milliseconds;
            auto diff = chrono::high_resolution_clock::now() - this->start_time_;

            return duration_cast<milliseconds>(diff).count() >= time_threshold_;
        }
};


using State = MazeState;
mt19937 mt_for_action(1);

int randomAction(const State& state) {
    auto legal_actions = state.legalActions();
    return legal_actions[mt_for_action() % ((int)legal_actions.size())];
}


int greedyAction(const State& state) {
    auto legal_actions = state.legalActions();
    ScoreType best_score = -INF;
    int best_action = -1;
    for (const auto action : legal_actions) {
        State now_state = state;
        now_state.advance(action);
        now_state.evaluateScore();

        if (now_state.evaluated_score_ > best_score) {
            best_score = now_state.evaluated_score_;
            best_action = action;
        }
    }

    return best_action;
}


vector<int> BeamSearchAction(const State& state, const int beam_width, const int beam_depth) {
    vector<State> now_beam;
    vector<State> next_beam;
    State best_state;

    now_beam.emplace_back(state);
    auto hash_check = unordered_set<uint64_t>();

    for (int t = 0; t < beam_depth; t++) {
        for (const State& now_state : now_beam) {
            auto legal_actions = now_state.legalActions();
            for (const auto& action : legal_actions) {
                State next_state = now_state;
                next_state.advance(action);
                if (t >= 1 && hash_check.count(next_state.hash_) > 0) {
                    continue;
                }
                hash_check.emplace(next_state.hash_);
                next_state.evaluateScore();

                if (t == 0) next_state.first_action_ = action;
                next_beam.emplace_back(next_state);
            }
        }

        if (next_beam.size() > beam_width) {
            nth_element(next_beam.begin(), next_beam.begin() + beam_width,
                        next_beam.end(), greater<>());
            next_beam.resize(beam_width);
        }

        swap(now_beam, next_beam);

        if (next_beam[0].isDone()) break;
    }

    for (const State& now_state : now_beam) {
        if (now_state.evaluated_score_ > best_state.evaluated_score_) {
            best_state = now_state;
        }
    }

    return best_state.all_actions_;
}


// int BeamSearchActionWithTimeThreshold(const State& state, const int beam_width, const int64_t time_threshold) {
//     priority_queue<State> now_beam;
//     State best_state;
//     auto time_keeper = TimeKeeper(time_threshold);

//     now_beam.push(state);
//     for (int t = 0 ;; t++) {
//         priority_queue<State> next_beam;
//         for (int i = 0; i < beam_width; i++) {
//             if (now_beam.empty()) break;
//             if (time_keeper.isTimeOver()) return best_state.first_action_;

//             State now_state = now_beam.top();
//             now_beam.pop();

//             auto legal_actions = now_state.legalActions();
//             for (const auto& action : legal_actions) {
//                 State next_state = now_state;
//                 next_state.advance(action);
//                 next_state.evaluateScore();

//                 if (t == 0) next_state.first_action_ = action;
//                 next_beam.push(next_state);
//             }
//         }

//         now_beam = next_beam;
//         best_state = now_beam.top();

//         if (best_state.isDone()) break;
//     }

//     return best_state.first_action_;
// }


void playGame(vector<vector<string>> &selected) {
    auto state = State(selected);
    string ans = "RLDU";

    vector<int> all_actions_ = BeamSearchAction(state, 3, END_TURN);
    // state.advance(BeamSearchActionWithTimeThreshold(state, 5, 10));

    for (int action : all_actions_) cout << ans[action];
    cout << endl;
}

bool operator> (const MazeState& maze_1, const MazeState& maze_2) {
    return maze_1.evaluated_score_ > maze_2.evaluated_score_;
}

vector<vector<string>> selectMap(vector<vector<string>> mp)
{
    vector<pair<int, int>> cnts;

    for (int i = 0; i < N; i++) {
        int cnt = H*W;
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                if (mp[i][j][k] == 'o') cnt--;
            }
        }
        cnts.emplace_back(cnt, i);
    }

    sort(cnts.begin(), cnts.end());

    vector<vector<string>> ret(K, vector<string>(H, string(W, ' ')));
    for (int i = 0; i < K; i++) {
        cout << cnts[i].second << (i == K-1 ? '\n' : ' ');
        for (int j = 0; j < H; j++) {
            for (int k = 0; k < W; k++) {
                ret[i][j][k] = mp[cnts[i].second][j][k];
            }
        }
    }

    return ret;
}

int main() {
    int n, k, h, w, t;
    cin >> n >> k >> h >> w >> t;

    vector<vector<string>> mp(N, vector<string>(H));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < H; j++) {
            cin >> mp[i][j];
        }
    }

    vector<vector<string>> selected(K, vector<string>(H, string(W, ' ')));
    selected = selectMap(mp);

    zobrist_hash::init();
    playGame(selected);

    return 0;
}
