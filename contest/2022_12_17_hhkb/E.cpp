#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

struct edge {
    int u;
    int v;
    int cost;

    bool operator<(const edge &e) {
        return cost < e.cost;
    }
};


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
        if (par.at(x) > par.at(y)) swap(x, y);
        par.at(x) += par.at(y);
        par.at(y) = x;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }
};


ll modpow(ll a, ll y, int m)
{
    ll ret = 1;
    
    while (y > 0) {
        if (y & 1) ret = ret * a % m;
        a = a * a % m;
        y >>= 1;
    }

    return ret;
}


ll maximun_spanning_tree(int n, vector<edge> &G)
{
    UnionFind uf(n+1);
    ll ret = 0;

    sort(G.rbegin(), G.rend());

    for (edge e : G) {
        int u = e.u;
        int v = e.v;
        if (uf.equal(u, v)) continue;

        uf.unite(u, v);
        ret += e.cost;
    }

    return ret;
}



int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<edge> G;

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            struct edge tmp;
            int score = (modpow(a[i], a[j], m) + modpow(a[j], a[i], m)) % m;
            tmp.u = i; tmp.v = j;
            tmp.cost = score;
            G.push_back(tmp);
        }
    }

    cout << maximun_spanning_tree(n, G) << endl;

    return 0;
}