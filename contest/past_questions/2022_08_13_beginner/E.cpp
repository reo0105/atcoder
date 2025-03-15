#include <bits/stdc++.h>
using namespace std;

struct UnionFind
{
    // データiが属する木の親番号
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
        if (par.at(x) > par.at(y)) swap(x, y);
        par.at(x) += par.at(y);
        par.at(y) = x;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }

    int size(int n) {
        return -par.at(root(n));
    }
};


int main()
{
    int n, m, e;
    cin >> n >> m >> e;

    UnionFind uf(n+m+1);
    vector<int> u(500005), v(500005);
    vector<vector<int>> G(200005);

    for (int i = 1; i <= e; i++) {
        int x, y;
        cin >> x >> y;
        if (x > n) x = n+1;
        if (y > n) y = n+1;
        // if (x == y) continue;
        u.at(i) = x; v.at(i) = y;
    }

    int q;
    set<int> s;
    vector<int> add(500005);

    cin >> q;
    for (int i = 0; i < q; i++) {
        cin >> add.at(i);
        s.insert(add.at(i));
    }

    for (int i = 1; i <= e; i++) {
        if (!s.count(i)) {
            uf.unite(u.at(i), v.at(i));
            // G.at(u.at(i)).push_back(v.at(i));
            // G.at(v.at(i)).push_back(u.at(i));
        }
    }

    vector<int> ans(500005, 0);
    ans.at(q) = uf.size(n+1)-1;

    for (int i = q-1; i > 0; i--) {
        if (!uf.equal(u.at(add.at(i)), v.at(add.at(i)))) {
            uf.unite(u.at(add.at(i)), v.at(add.at(i)));
        }
        ans.at(i) = uf.size(n+1)-1;
    }

    for (int i = 1; i <= q; i++) {
        cout << ans.at(i) << endl;
    }


    return 0; 
}
