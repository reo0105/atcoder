#include <bits/stdc++.h>
using namespace std;

struct UnionFind {
    vector<int> pair;

    UnionFind(int n) {
        pair.assign(n, -1);
    }

    int root(int x) {
        return (pair.at(x) < 0) ? x : (pair.at(x) = root(pair.at(x)));
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return;
        if (pair.at(x) > pair.at(y)) swap(x, y);
        pair.at(x) += pair.at(y);
        pair.at(y) = x;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    } 
};

int main()
{
    int n, m;
    int ans = 0;
    UnionFind uf(200005);
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        if (uf.equal(a, b)) ans++;
        else uf.unite(a, b);
    }

    cout << ans << endl;
    return 0;
}