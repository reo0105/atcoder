#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

struct UnionFind{
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
    int n, q;

    cin >> n >> q;

    UnionFind uf(n+1);

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        uf.unite(l-1, r);
    }

    if (uf.equal(0, n)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}