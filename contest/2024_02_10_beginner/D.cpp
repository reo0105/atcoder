#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, int> pli;

ll dijkstra(vector<vector<pii>> &G, int n)
{
    priority_queue<pli, vector<pli>, greater<pli>> que;
    vector<ll> cost(n+5, 2e18);

    que.push(make_pair(0LL, 0));

    while (que.size()) {
        ll c = que.top().first;
        int stage = que.top().second;

        que.pop();

        if (cost[stage] < c) continue;

        for (pii gs : G[stage]) {
            int ns = gs.first;
            ll nc = c + gs.second;

            if (nc < cost[ns]) {
                cost[ns] = nc;
                que.push(make_pair(nc, ns));
            }
        }
    }

    return cost[n-1];
}

int main()
{
    int n;
    cin >> n;

    vector<vector<pii>> G(n);

    for (int i = 0; i < n-1; i++) {
        int a, b, x;
        cin >> a >> b >> x;
        G[i].push_back(make_pair(i+1, a));
        G[i].push_back(make_pair(x-1, b));
    }

    cout << dijkstra(G, n) << endl;


    return 0;
}