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

    vector<int> u(500005), v(500005);
    vector<int> add(500005);
    set<int> s;
    int q;

    for (int i = 1; i <= e; i++) {
        int x, y;
        cin >> x >> y;
        if (x > n) x = n+1;
        if (y > n) y = n+1;
        u.at(i) = x;
        v.at(i) = y;
    }

    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        s.insert(x);
        add.at(i) = x;
    }

    UnionFind uf(n+2);
    for (int i = 1; i <= e; i++) {
        if (s.count(i)) continue;
        uf.unite(u.at(i), v.at(i));
    }

    vector<int> ans(500005);
    ans.at(q) = (int)uf.size(n+1); 
    for (int i = q-1; i > 0; i--) {
        int x = add.at(i);
        uf.unite(u.at(x), v.at(x));
        ans.at(i) = (int)uf.size(n+1);
    }

    for (int i = 1; i <= q; i++) cout << ans.at(i)-1 << endl;

    return 0;
}