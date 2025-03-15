#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
struct edge {
    int to;
    ll cost;
    edge (int to, ll cost) : to(to), cost(cost) {}
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> x(m), y(m), z(m);
    for (int i = 0; i < m; i++) cin >> x[i] >> y[i] >> z[i];

    vector<int> ans(n);
    vector<vector<edge>> G(n);
    vector<bool>visited(n, false);

    for (int i = 0; i < m; i++)
    {
        x[i]--;
        y[i]--;
        G[x[i]].emplace_back(y[i], z[i]);
        G[y[i]].emplace_back(x[i], z[i]);
    }

    auto dfs = [&](auto dfs, int from, vector<int>& connect) -> bool {

        bool ret = true;
        connect.push_back(from);
        for (edge e : G[from])
        {
            int to = e.to;
            int c = e.cost;
            
            if (visited[to]) 
            {
                if ((ans[from]^ans[to]) != c) return false;
            }
            else
            {
                ans[to] = c^ans[from];
                visited[to] = true;
                ret &= dfs(dfs, to, connect);
                // visited[to] = false;
            }
        }

        return ret;
    };

    bool ok = true;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            vector<int> connect;
            visited[i] = true;
            ok &= dfs(dfs, i, connect);

            for (int i = 0; i < 32; i++)
            {
                int cnt = 0;
                int mask = 1<<i;

                for (int u : connect)
                {
                    if ((ans[u] & mask) != 0) cnt++; 
                }

                if ((int)connect.size() - cnt < cnt)
                {
                    for (int i = 0; i <(int)connect.size(); i++)
                    {
                        ans[connect[i]] ^= mask;
                    }
                }
            }
        }
    }

    if (ok)
    {
        for (int i = 0; i < n; i++) cout << ans[i] << (i == n-1 ? '\n' : ' ');
    }
    else 
    {
        cout << -1 << endl;
    }

    return 0;
}