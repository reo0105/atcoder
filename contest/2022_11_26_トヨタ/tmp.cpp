#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    vector<int> par;

    UnionFind(int n) {
        par.assign(n, -1);
    }

    int root(int x) {
        return par.at(x) < 0 ? x : par.at(x) = root(par.at(x));
    }

    int unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return -1;
        par.at(x) += par.at(y);
        par.at(y) = x;
        return x;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    UnionFind uf(n+q+1);
    vector<int> g2b(n+q+1);
    vector<int> b2g(n+q+1);

    for (int i = 0; i < n; i++) g2b.at(i) = i;
    for (int i = 0; i < n; i++) b2g.at(i) = i;

    int next = n;
    for (int i = 0; i < q; i++) {
        int qi, x, y;
        cin >> qi >> x;
        x--;
        if (qi == 1) {
            int y;
            cin >> y;
            y--;
            int leader = uf.unite(x, y);
            g2b.at(y) = leader;
        } else if (qi == 2) {
            int leader = uf.root(x);
            int leader = uf.unite(x);
            
        } else {
            int leader = uf.root(x);
            cout << g2b.at(leader)+1 << endl;
        }
    }

    return 0;
}