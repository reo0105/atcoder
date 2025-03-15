#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct UnionFind {
    vector<int> par;
    
    UnionFind(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        return par[x] < 0 ? x : par[x] = root(par[x]);
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (x > y) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }

    int size(int x) {
        return -par[x];
    }

};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> to(n);
    UnionFind uf(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        to[a].push_back(b);
        to[b].push_back(a);
        uf.unite(a, b);
    }

    map<int, int> roots;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        if (!roots.count(i)) {
            int root = uf.root(i);
            int sz = uf.size(root);
            roots[root] = sz;
            // ans += (long long)sz*(sz-1) / 2;
            ans += (sz - 1 - (int)to[i].size());
        } else {
            int root = uf.root(i);
            int sz = roots[root];
            ans += (sz - 1 - (int)to[i].size());
        }
        // cout << ans << endl;
    }

    cout << ans / 2 << endl;

    return 0;
}