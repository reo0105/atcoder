#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        return par[x] < 0 ? x : (par[x] = root(par[x]));
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (x < y) swap(x, y);
        par[y] += par[x];
        par[x] = y;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    UnionFind uf(n+1);
    vector<pii> edges;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        if (a[u] == a[v]) uf.unite(u, v);
        edges.push_back(make_pair(u, v));
    }

    vector<vector<int>> to(n);

    for (pii e : edges) {
        int u = uf.root(e.first);
        int v = uf.root(e.second);
        if (u == v) continue;
        if (a[u] > a[v]) swap(u, v);
        to[u].push_back(v);
    }

    vector<int> vs;
    for (int i = 0; i < n; i++) {
        if (uf.root(i) == i) {
            vs.push_back(i);
        }
    }

    sort(vs.begin(), vs.end(), [&](int u, int v) {
        return a[u] < a[v];
    });

    vector<int> dp(n, -1e9);
    dp[uf.root(0)] = 1;
    for (int ui : vs) {
        for (int vi : to[ui]) {
            dp[vi] = max(dp[vi], dp[ui] + 1);
        }
    }

    cout << (dp[uf.root(n-1)] < 0 ? 0 : dp[uf.root(n-1)]) << '\n';    

    return 0;
}