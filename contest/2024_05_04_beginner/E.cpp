#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
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
};

struct edge {
    int u, v, c;
    edge(int u, int v, int c): u(u), v(v), c(c) {}
    bool operator<(const edge &e) {
        return c < e.c;
    }
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<edge> g;
    for (int i = 0; i < m; i++) {
        int k, c;
        cin >> k >> c;
        int a;
        cin >> a;
        a--;
        for (int j = 0; j < k-1; j++) {
            int b;
            cin >> b;
            b--;
            g.emplace_back(a, b, c);
        }
    }

    sort(g.begin(), g.end());

    ll ans = 0;
    UnionFind uf(n);
    for (edge e : g) {
        int u = e.u;
        int v = e.v;

        if (uf.equal(u, v)) continue;
        ans += e.c;
        uf.unite(u, v);
    }

    for (int i = 1; i < n; i++) {
        if (!uf.equal(0, i)) ans = -1;
    }

    cout << ans << endl;

    return 0;
}