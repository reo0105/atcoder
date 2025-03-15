#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define INF 1e18


struct WeightedUnionFind {
    vector<int> par;
    vector<ll> diff;  //重みの差分

    WeightedUnionFind (int n) { 
        par.assign(n, -1);
        diff.assign(n, 0);
    }

    int root(int x) {
        // return par[x] < 0 ? x : (par[x] = root(par[x]));
        if (par[x] < 0) return x;
        int px = par[x];
        par[x] = root(px);
        diff[x] += diff[px];
        return par[x];
    }

    bool unite(int x, int y, ll w) { // x = y + w
        int px = root(x); 
        int py = root(y);
        w = w + diff[x] - diff[y]; // yの親からxの親への重み
        if (px == py) return w == 0; //同じ連結成分の場合重みに矛盾がないか
        if (px > py) { swap(px, py); w = -w; }
        par[px] += par[py];
        par[py] = px;
        diff[py] = w;
        return true;
    }
};


int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> ans;
    WeightedUnionFind uf(n+1);

    for (int i = 0; i < q; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        if (uf.unite(a, b, d)) ans.push_back(i+1);
    }

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}