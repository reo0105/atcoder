#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pli;

#define INF 1e18

vector<ll> Dijkstra(int from, int n, int x, int y, vector<vector<int>> &d)
{
    vector<ll> dist(n, INF);
    priority_queue<pli, vector<pli>, greater<pli>> que;

    dist[from] = 0;
    que.push(make_pair(0, from));

    while (que.size()) {
        pli now = que.top();
        que.pop();

        ll c = now.first;
        int u = now.second;

        if (dist[u] < c) continue;

        for (int i = 0; i < n; i++) {
            if (i == u) continue;

            ll nc = c + (ll)d[u][i] * x + y;
            if (dist[i] > nc) {
                dist[i] = nc;
                que.push(make_pair(nc, i));
            }
        }
    }
    
    return dist;
}


int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    vector<vector<int>> d(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    vector<ll> dist1 = Dijkstra(0, n, a, 0, d);   
    vector<ll> distn = Dijkstra(n-1, n, b, c, d);   
    
    ll ans = dist1[0] + distn[0];

    for (int i = 0; i < n; i++) {
        ans = min(ans, dist1[i] + distn[i]);
    }
    
    cout << ans << endl;

    return 0;
}