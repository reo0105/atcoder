#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
typedef pair<int, int> p;

vector<vector<int>> G(200005);
vector<int> seen(200005, false);
stack<int> cycle;
int found = 0;
int edge;

void dfs(int from, int par)
{
    seen.at(from) = true;
    cycle.push(from);

    for (int v : G.at(from)) {
        if (v == par) continue;
        if (seen.at(v)) {
            found = 1;
            edge = v;
            return;
        }

        dfs(v, from);
        
        if (found) return;
    }

    cycle.pop();
}

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
        par.at(x) += par.at(y);
        par.at(y) = x;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }
};

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    dfs(1, -1);

    set<int> root;
    while (cycle.size()) {
        int v = cycle.top();
        cycle.pop();
        root.insert(v);
        // cout << v << " ";
        if (edge == v) break;
    }

    UnionFind uf(n+1);

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