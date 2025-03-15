#include <bits/stdc++.h>
using namespace std;

// vector<vector<int>> G(200005);

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
        par.at(y) += par.at(x);
        par.at(x) = y;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }
};

int main()
{
    int n, q;
    cin >> n >> q;

    // vector<int> sum(200005, 0);
    UnionFind uf(n+1);

    for (int i = 0 ; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        // G.at(l).push_back(r);
        // G.at(r).push_back(l);
        uf.unite(l, r);
    }

    if (uf.equal(0, n)) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}