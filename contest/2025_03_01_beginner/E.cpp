#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

ll dijkstra(vector<vector<pii>> &G, int n, int x)
{
    priority_queue<pli, vector<pli>, greater<pli>> que;
    vector<ll> cost(2*n+5, 2e18);

    que.push(make_pair(0LL, 0));

    while (que.size()) {
        ll c = que.top().first;
        int stage = que.top().second;

        que.pop();

        if (cost[stage] < c) continue;

        for (pii gs : G[stage]) {
            int ns = gs.first;
            ll nc = c + gs.second;

            int u;
            ll uc = nc + x;
            if (ns >= n) {
                u = ns-n;
            } else {
                u = ns+n;
            }

            if (uc < cost[u]) {
                cost[u] = uc;
                que.push(make_pair(uc, u));
            }
            if (nc < cost[ns]) {
                cost[ns] = nc;
                que.push(make_pair(nc, ns));
            }
        }
    }

    // for (int i = 0; i < 2*n; i++) cout << cost[i] << " ";
    // cout << endl;

    return cost[n-1];
}

int main()
{
    int n, m, x;
    cin >> n >> m >> x;

    vector<vector<pii>> G(2*n);
    vector<int> u(m), v(m);

    for (int i = 0; i < m; i++) {
        cin >> u[i] >> v[i];
        u[i]--; v[i]--;
        G[u[i]].emplace_back(v[i], 1);
        G[u[i]].emplace_back(u[i]+n, x);
        G[v[i]].emplace_back(v[i]+n, x);
        G[v[i]+n].emplace_back(u[i]+n, 1);
        // G[u[i]].emplace_back(v[i]+n, x+1);
    }
    G[2*n-1].emplace_back(n-1, 0);

    cout << dijkstra(G, n, x) << endl;

    return 0;
}