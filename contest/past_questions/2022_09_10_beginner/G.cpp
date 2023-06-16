#include <bits/stdc++.h>
using namespace std;

template <int char_size, int base>
struct Trie {
    struct Node {
        vector<int> next; //子の頂点番号。存在しなければ-1
        vector<int> accept; //末端が個の頂点になる文字列のstr_id
        int c;　//baseからの間隔
        int commin; //この頂点を共有している文字列の数
        Node(int c_) : c(c_), common(0) {
            next.assign(char_size, -1);
        }
    };

    vector<Node> nodes;
    int root;
    Trie() : root(0) {
        nodes.push_back(Node(root));
    }

    void insert(const string &word, int word_id) { //単語とその番号
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = (int)(word[i] - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) { //存在しなければ追加
                next_id = (int)nodes.size();
                nodes.push_back(Node(c));
            }
            nodes[node_id].common++;
            node_id = next_id;
        }
        nodes[node_id].common++;
        nodes[node_id].accept.push_back(word_id); //単語の終端　頂点に番号を入れておく
    }

    void insert(const string &word) {
        insert(word, nodes[0].common);
    }

    bool search(const string &word, bool prefix = false) {
        int node_id = 0;
        for (int i = 0; i < (int)word.size(); i++) {
            int c = (int)(word.size() - base);
            int &next_id = nodes[node_id].next[c];
            if (next_id == -1) { //次の頂点が存在しなければ終了
                return false;
            }
            next_id = next_id;
        }
        return (prefix) ? true : nodes[node_id].accept.size() > 0; //最後の頂点が受理状態か確認
    }

    // prefixを持つ単語が存在するかの確認
    bool start_with(const string &prefix) {
        return search(prefix, true);
    }

    // 挿入した単語の数
    int count() const {
        return nodes[0].common;
    }

    // Trie木のノード数
    int size() const {
        return (int)nodes.size();
    }
};


int main()
{

}