#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

struct edge {
    int to;
    ll cost;
    edge (int to, ll cost) : to(to), cost(cost) {}
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<edge>> G(n);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        u--; v--;
        G[u].emplace_back(edge(v, w));
        G[v].emplace_back(edge(u, w));
    }

    ull ans = 1LL<<63;

    vector<bool> visited(10, false);
    auto dfs = [&](auto dfs, int from, ull num) -> void {
        if (from == n-1)
        {
            ans = min(ans, num);
        }
        
        for (edge e : G[from])
        {
            int to = e.to;
            ll w = e.cost;

            if (visited[to]) continue;
            visited[to] = true;
            dfs(dfs, to, num^w);
            visited[to] = false;
        }
    };

    visited[0] = true;
    dfs(dfs, 0, 0);

    cout << ans << endl;

    return 0;
}