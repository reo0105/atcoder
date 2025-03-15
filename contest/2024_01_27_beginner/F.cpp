#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> dist(n+1, vector<int>(n+1, 1e9));

    for (int i = 0; i < n; i++) dist[i][i] = 0;

    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;
        dist[u][v] = min(dist[u][v], w);
        // dist[v][u] = min(dist[v][u], w);
    }

    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }


    vector<vector<int>> dp(1<<21, vector<int>(n+1, 1e9));

    for (int i = 0; i < n; i++) dp[1<<i][i] = 0;
    for (int s = 0; s < (1<<n); s++) {
        for (int i = 0; i < n; i++) {
            // if (s != 0 && ((s>>i) & 1) == 0) continue;
            if (dp[s][i] == 1e9) continue;

            for (int j = 0; j < n; j++) {
                if (((s>>j)&1) == 0 && dist[i][j] != 1e9) {
                    dp[s|(1<<j)][j] = min(dp[s|(1<<j)][j], dp[s][i] + dist[i][j]);
                }
            }
        }
    }

    int s = (1<<n)-1;
    int ans = 1e9;

    for (int i = 0; i < n; i++) ans = min(ans, dp[s][i]);

    if (ans == 1e9) {cout << "No" << endl; return 0;}

    cout << ans << endl;

    return 0;
}