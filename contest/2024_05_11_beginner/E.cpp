#include <bits/stdc++.h>
using namespace std;

struct Trie {
    struct Node {
        int cnt;
        map<char, int> to;
        Node (): cnt(0) {}
    };
    vector<Node> d;
    Trie(): d(1) {}

    void add(const string &s) {
        int v = 0;
        for (char c : s) {
            if (!d[v].to.count(c)) {
                d[v].to[c] = (int)d.size();
                d.push_back(Node());
            }
            v = d[v].to[c];
        }
        d[v].cnt++;
    }

    long long ans;
    int dfs(int v) {
        int res = d[v].cnt;
        for (auto p : d[v].to) {
            // cout << v << " " << p.second << " " << res << endl;
            res += dfs(p.second);
            // cout << v << " " << p.second << " " << res << endl;
        }
        if (v) ans += (long long)res*(res-1)/2;
        return res;
    }

    long long solve() {
        ans = 0;
        dfs(0);
        return ans;
    }

};

int main() {
    int n;
    cin >> n;

    Trie t;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        t.add(s);
    }

    long long ans = t.solve();
    cout << ans << endl;

    return 0;
}