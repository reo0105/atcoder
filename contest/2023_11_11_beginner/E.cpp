#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 1e18

struct edge {
    int u, v;
    ll w;
    edge(int u, int v, ll w) : u(u), v(v), w(w) {}
};


struct UnionFind {
    vector<int> par;

    UnionFind (int n) { 
        par.assign(n, -1); 
    }

    int root(int x) {
        return par[x] < 0 ? x : (par[x] = root(par[x]));
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return ;
        if (x > y) swap(x, y);
        par[x] += par[y];
        par[y] = x;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }
};


ll dfs(int from, int n, int m, ll k, ll& ans, vector<edge> G, vector<int> ids)
{
    if ((int)ids.size() == n-1) {
        UnionFind uf(n+1);
        int ok = 1;
        ll sum = 0;
        for (int id : ids) {
            int u = G[id].u;
            int v = G[id].v;
            ll w = G[id].w;
            if (uf.equal(u, v)) ok = 0;
            uf.unite(u, v);
            sum += w;
        }
        if (ok) return sum % k;
        else return INF;
    }
    if (from == m) return INF;
    ans = min(ans, dfs(from+1, n, m, k, ans, G, ids));
    ids.push_back(from);
    ans = min(ans, dfs(from+1, n, m, k, ans, G, ids));
    return ans;
}


int main()
{
    int n, m;
    ll k;
    cin >> n >> m >> k;

    vector<edge> G;

    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        G.emplace_back(edge(u, v, w));
    }

    ll ans = INF;
    vector<int> ids;

    dfs(0, n, m, k, ans, G, ids);

    cout << ans << endl;

    return 0;
}