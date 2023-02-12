#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

/*
元のグラフの最小全域木 T を構築する
クエリ (u,v,w) に対する答えは、T の u−v パスに含まれる辺の最大重みが w より大きいとき Yes、小さいとき No

この方法でやろうとしたけど、u-vパスに含まれる辺の重みはダブリングによりＬＣＡを求めるのでやるらしいけどこれがよくわからんからへ入れるにクエリを処理する
*/

struct edge{
    int u;
    int v;
    int cost;
    int flag;
    bool operator< (const edge& o) {
        return cost < o.cost;
    }
};

struct UnionFind {
    vector<int> par;

    UnionFind(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        return (par.at(x) < 0) ? x : (par.at(x) = root(par.at(x)));
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


int main()
{
    int n, m, q;
    vector<edge> G;

    cin >> n >> m >> q;

    for (int i = 0; i < m; i++) {
        int a, b, c;
        struct edge tmp;
        cin >> a >> b >> c;
        tmp.u = a; tmp.v = b; tmp.cost = c; tmp.flag = 0;
        G.push_back(tmp);
    }

    for (int i = 1; i <= q; i++) {
        int qu, qv, qw;
        struct edge tmp;
        cin >> qu >> qv >> qw;
        tmp.u = qu; tmp.v = qv; tmp.cost = qw; tmp.flag = i;
        G.push_back(tmp);
    }

    UnionFind uf(n+1);
    vector<bool> ans(q+1);

    sort(G.begin(), G.end());

    for (auto next : G) {
        if (uf.equal(next.u, next.v)) {
            if (next.flag != 0) ans.at(next.flag) = false;
            continue; 
        }
        
        if (next.flag != 0) {
            ans.at(next.flag) = true;
        } else {
            uf.unite(next.u, next.v);
        }
    }

    for (int i = 1; i <= q; i++) {
        if (ans.at(i)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}


// struct UnionFind {
//     vector<p> par;

//     UnionFind(int n) {
//         par.assign(n, make_pair(-1, 1L<<58));
//     }

//     int root(int x) {
//         return (par.at(x).first < 0) ? x : (par.at(x).first = root(par.at(x).first));
//     }

//     void unite(int x, int y, int c) {
//         x = root(x);
//         y = root(y);
//         if (x == y) return;
//         if (par.at(x).first > par.at(y).first) swap(x, y);
//         par.at(x).first += par.at(y).first;
//         par.at(y).first = x;
//         par.at(y).second = c;
//     }

//     bool equal(int x, int y) {
//         return root(x) == root(y);
//     }
// };

// int main()
// {
//     int n, m, q;
//     vector<edge> G;

//     cin >> n >> m >> q;

//     for (int i = 0; i < m; i++) {
//         int a, b, c;
//         struct edge tmp;
//         cin >> a >> b >> c;
//         tmp.u = a; tmp.v = b; tmp.cost = c; ;
//         G.push_back(tmp);
//     }

//     UnionFind uf(n+1);

//     sort(G.begin(), G.end());

//     for (auto next : G) {
//         if (uf.equal(next.u, next.v)) continue;
//         cout << next.u << " " << next.v << " " << next.cost << endl;
//         uf.unite(next.u, next.v, next.cost);
//     }

//     for (int i = 0; i < q; i++) {
//         int qu, qv, qw;
//         cin >> qu >> qv >> qw;

//         ll cnt = uf.par.at(qu).second;
//         while (uf.par.at(qu).first != qv) {

//         }
//     }

//     return 0;
// }