#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define INF 1e18

vector<ll> Dijkstra(int from, int n, int a, int b, vector<vector<int>> d)
{
    vector<ll> dist(n+1, INF);    
    priority_queue<pll, vector<pll>, greater<pll>> que;

    dist[from] = 0;
    que.push(make_pair(0, from));

    while (que.size()) {
        pll p = que.top();
        que.pop();

        ll c = p.first;
        int u = p.second;

        if (dist[u] != c) continue;

        for (int v = 0; v < n; v++) {
            ll nc = c + (ll)d[u][v] * a + b;

            if (dist[v] > nc) {
                dist[v] = nc;
                que.push(make_pair(nc, v));
            }
        }
    }

    return dist;
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    vector<vector<int>> d(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> d[i][j];
        }
    }

    vector<ll> dist1 = Dijkstra(0, n, a, 0, d);
    vector<ll> distn = Dijkstra(n-1, n, b, c, d);

    ll ans = INF;
    for (int i = 0; i < n; i++) {
        ans = min(ans, dist1[i]+distn[i]);
    }

    cout << ans << endl;
    return 0;
}