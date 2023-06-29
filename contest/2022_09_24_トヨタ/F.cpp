#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

struct edge {
    int u;
    int v;
    int cost;
    bool operator<(const edge &e) {
        return cost < e.cost;
    }
};

vector<edge> G;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        return par.at(x) < 0 ? x : par.at(x) = root(par.at(x));
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (x > y) swap(x, y);
        par.at(x) += par.at(y);
        par.at(y) = x;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }
};

ll mininum_spanning_tree(int n)
{
    sort(G.begin(), G.end());

    ll cost, ret = 1LL<<62;
    for (int i = 0; i < 4; i++) {
        UnionFind uf(n+3);
        cost = 0;
        int cnt = 0;

        for (edge e : G) {
            int u = e.u;
            int v = e.v;
            int c = e.cost;
            
            if (i == 0) {
                if (v == n+1 || v == n+2) continue;
            } else if (i == 1) {
                if (v == n+2) continue;
            } else if (i == 2) {
                if (v == n+1) continue;
            }
            if (uf.equal(u, v)) continue;
            else {
                cost += c;
                uf.unite(u, v);
                cnt++;
            }
        }

        int ok = 1;
        for (int i = 2; i <= n; i++) {
            if (!uf.equal(1, i)) ok = 0;
        }

        if (ok) ret = min(ret, cost);
    }

    return ret;
}

int main()
{
    int n, m, x, y;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        edge tmp;
        tmp.u = i; tmp.v = n+1;
        cin >> tmp.cost;
        G.push_back(tmp);
    }
    for (int i = 1; i <= n; i++) {
        edge tmp;
        tmp.u = i; tmp.v = n+2;
        cin >> tmp.cost;
        G.push_back(tmp);
    }
    for (int i = 0; i < m; i++) {
        edge tmp;
        cin >> tmp.u >> tmp.v >> tmp.cost;
        G.push_back(tmp);
    }

    ll ans = mininum_spanning_tree(n);

    cout << ans << endl;

    return 0;
}