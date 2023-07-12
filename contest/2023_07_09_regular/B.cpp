#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

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

int main()
{
    int n, m;
    cin >> n >> m;
    
    UnionFind uf(n+1);
    vector<int> a(200005), b(200005), c(200005);
    for (int i = 0; i < m; i++) cin >> a.at(i) >> b.at(i);
    for (int i = 1; i <= n; i++) cin >> c.at(i);

    for (int i = 0; i < m; i++) {
        int ai = a.at(i);
        int bi = b.at(i);

        if (c.at(ai) != c.at(bi)) uf.unite(ai, bi);
    }

    for (int i = 0; i < m; i++) {
        int ai = a.at(i);
        int bi = b.at(i);

        if (c.at(ai) == c.at(bi) && uf.equal(ai, bi)) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl; 
  
    return 0;
}