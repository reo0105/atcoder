#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct UnionFind {
    vector<int> par;

    UnionFind(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        return par.at(x) < 0 ? x : (par.at(x) = root(par.at(x)));
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

struct edge {
    int u, v;
    int id;
    int cost;

    bool operator< (const edge &e) {
        return cost < e.cost;
    }
};

vector<edge> G;
vector<bool> ans(200005, false);

void minimun_spanning_tree(int n)
{
    UnionFind uf(n+1);
    sort(G.begin(), G.end());

    for (edge e : G) {
        if (!uf.equal(e.u, e.v)) {
            if (e.id != -1) ans.at(e.id) = true;
            else uf.unite(e.u, e.v);
        }
    }

    return;
}

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        edge tmp;
        cin >> a >> b >> c;
        tmp.u = a;
        tmp.v = b;
        tmp.id = -1;
        tmp.cost = c;
        G.push_back(tmp);
    }

    for (int i = 0; i < q; i++) {
        int a, b, c;
        edge tmp;
        cin >> a >> b >> c;
        tmp.u = a;
        tmp.v = b;
        tmp.id = i;
        tmp.cost = c;
        G.push_back(tmp);
    }

    minimun_spanning_tree(n);

    for (int i = 0; i < q; i++) {
        if (ans.at(i)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}