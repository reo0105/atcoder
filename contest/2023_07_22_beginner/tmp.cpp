#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int h, w, n;
    cin >> h >> w >> n;

    vector<vector<ll>> dp(h+1, vector<ll>(w+1, -1L));
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        dp[a][b] = 0L;
    }
    for (int i = 0; i <= h; i++) dp[i][0] = 0L;
    for (int i = 0; i <= w; i++) dp[0][i] = 0L;

    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            if (dp[i][j] == 0L) continue;

            dp[i][j] = min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
            dp[i][j]++;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            ans += dp[i][j];
        }
    }

    cout << ans << endl;

    return 0;
}