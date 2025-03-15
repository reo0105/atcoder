#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, k, p;
    cin >> n >> k >> p;

    vector<int> c(n);
    vector<vector<int>> a(n, vector<int>(k));

    for (int i = 0; i < n; i++) {
        cin >> c[i];
        for (int j = 0; j < k; j++) cin >> a[i][j];
    }

    int piv = 1;
    for (int i = 0; i < k-1; i++) {
        piv *= 10;
    }

    const ll INF = 1e18;
    vector<vector<ll>> dp(n+5, vector<ll>(60005, INF));

    dp[0][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= 60000; j++) {
            if (dp[i-1][j] == INF) continue;

            int t = j;
            int tens =  piv;
            int next = 0;
            for (int ki = 0; ki < k; ki++) {
                int now = t / tens;
                t -= now * tens;
                if (now + a[i-1][ki] >= 5) next += 5 * tens;
                else next += (now + a[i-1][ki]) * tens;
                tens /= 10;
            }
            
            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            dp[i][next] = min(dp[i][next], dp[i-1][j] + c[i-1]);
        }
    }

    ll ans = INF;
    for (int i = 0; i <= 55555; i++) {
        int cnt = piv;
        int tmp = i;
        for (int j = 0; j < k; j++) {
            int now = tmp / cnt;
            tmp -= now * cnt;
            if (now < p) break;
            cnt /= 10;
        }
        if (cnt == 0) {
            ans = min(ans, dp[n][i]);
        }
    }

    if (ans == INF) ans = -1;
    cout << ans << endl;
    
    return 0;
}