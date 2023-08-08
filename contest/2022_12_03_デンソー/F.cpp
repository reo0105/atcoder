#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define INF 1e18

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

struct edge {
    int to;
    int cost;

    edge(int to, int c) : to(to), cost(c){}
};

int main()
{
    int n, m, q;
    cin >> n >> m >> q;

    UnionFind uf(n+1);
    vector<vector<edge>> G(100005);

    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        uf.unite(a, b);
        G.at(a).push_back(edge(b, c));
        G.at(b).push_back(edge(a, -c));
    }


    vector<ll> dist(100005, INF);
    vector<int> loop(100005, 0);

    for (int i = 1; i <= n; i++) {
        if (uf.root(i) == i) {
            queue<int> que;

            que.push(i);
            dist.at(i) = 0;

            while (que.size()) {
                int now = que.front();
                que.pop();

                for (edge e : G[now]) {
                    int v = e.to;
                    int c = e.cost;

                    if (dist[v] == INF) {
                        dist[v] = dist[now] + c;
                        que.push(v);
                    } else if (dist[v] != dist[now] + c) {
                        loop[i] = 1;
                    }
                }
            }
            
        }
    }

    for (int i = 0 ; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (!uf.equal(x, y)) {
            cout << "nan" << endl;
        } else if (loop[uf.root(x)]) {
            cout << "inf" << endl;
        } else {
            cout << dist[y] - dist[x] << endl; 
        }
    }
}