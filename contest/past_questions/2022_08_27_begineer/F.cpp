#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(200005);
vector<bool> seen(200005, false);
vector<bool> finished(200005, false);
stack<int> cycle;
bool found = false;
bool loop = false;
int pos = -1;

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
        if (par.at(x) > par.at(y)) swap(x, y); //サイズはマイナスで保持してる
        par.at(x) += par.at(y);
        par.at(y) = x; 
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }
};

void dfs(int from, int prev)
{
    seen.at(from) = true;
    cycle.push(from);

    for (int n : G.at(from)) {
        if (n == prev) continue;

        if (finished.at(n)) continue;

        if (seen.at(n) && !finished.at(n)) {
            pos = n;
            return;
        }

        dfs(n, from);

        if (pos != -1) return;
    }

    cycle.pop();
    finished.at(from) = true;
}

int main()
{
    int n;
    cin >> n;
    UnionFind uf(n+1);

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    dfs(1, -1);

    set<int> root;
    while (cycle.size()) {
        int t = cycle.top();
        // cout << t << " ";
        cycle.pop();
        root.insert(t);
        if (t == pos) break;
    }

    //サイクルの含まれる頂点を根としてufをして、クエリごとに同木なら一意
    for (int u = 1; u <= n; u++) {
        for (int v : G.at(u)) {
            if (root.count(u) && root.count(v)) continue;

            uf.unite(u, v);
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (uf.equal(x, y)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}