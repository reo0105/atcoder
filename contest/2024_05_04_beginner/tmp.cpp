#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
    int u, v, c;
    edge(int u, int v, int c): u(u), v(v), c(c) {}

    bool operator<(const edge &e) {
        return c < e.c;
    }
};

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
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<edge> g;
    for (int i = 0; i < m; i++) {
        int k, c;
        cin >> k >> c;

        int u, v;
        cin >> u;
        for (int j = 1; j < k; j++) {
            cin >> v;
            g.emplace_back(u, v, c);
        }
    }

    sort(g.begin(), g.end());

    ll ans = 0;
    UnionFind uf(n+1);
    int cnt = 0;
    for (edge e : g) {
        int u = e.u;
        int v = e.v;
        int c = e.c;

        if (uf.equal(u, v)) continue;
        ans += c;
        uf.unite(u, v);
        cnt++;
    }

    if (cnt != n-1) ans = -1;
    cout << ans << endl;

    return 0;
}