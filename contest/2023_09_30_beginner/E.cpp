#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, k, p;
    cin >> n >> k >> p;

    // vector<vector<vector<vector<ll>>>> dp(105, vector<vector<vector<ll>>>(40, vector<vector<ll>>(11, vector<ll>(11, 2e18))));

    vector<int> c(105);
    vector<vector<int>> a(105, vector<int>(11));

    for (int i = 1; i <= n; i ++) {
        cin >> c[i];
        for (int j = 1; j <= k; j++) {
            cin >> a[i][j];
        }
    }

    int start = 1;
    for (int i = 0; i < k; i++) {
        start *= 10;
    }
    start /= 10;

    vector<vector<ll>> dp(105, vector<ll>(66666, 2e18));

    dp[0][0] = 0;
    
    for (int i = 1; i <= n; i++) {
        int now = 0;
        for (int j = 0; j <= 60000; j++) {
            if (dp[i-1][j] == 2e18) continue;
            int digi = start;
            int temp = j;
            int update = 0;
            for (int l = 1; l <= k; l++) {
                int now = temp / digi;
                temp -= now * digi;
                if (now + a[i][l] >= 5) update += 5 * digi;
                else update += (now + a[i][l]) * digi;
                digi /= 10;
            }

            dp[i][j] = min(dp[i][j], dp[i-1][j]);
            dp[i][update] = min(dp[i][update], dp[i-1][j] + c[i]);
        }
    }

    int id = p;
    for (int i = 0; i < k-1; i++) {
        id = id * 10 + p;
    }

    ll ans = 2e18;
    for (int i = 0; i <= 55555; i++) {
        int cnt = start;
        int temp = i;
        for (int j = 0; j < k; j++) {
            int now = temp / cnt;
            temp -= now * cnt;
            if (now < p) break;
            cnt /= 10;
        }
        if (cnt == 0) {
            ans = min(ans, dp[n][i]);
        }
    }

    // cout << start << " " << id << endl;

    if (ans == 2e18) cout << -1 << endl;
    else cout << ans << endl;

    // for (int i = 0; i <= 39; i++) {
    //     for (int j = 0; j <= 10; j++) {
    //         for (int k = 0; k <= 10; k++) {
    //             dp[0][i][j][k] = 0;
    //         }
    //     }
    // }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= k; j++) {
    //         for (int l = 0; l <= p; l++) {
    //             if (l >= a[i][j]) dp[i][j][l] = min(dp[i-1][j][l-a[i][j]] + c[i], dp[i][j][l]);
    //         }
    //     }
    // }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 0; j < (1<<k); j++) {
    //         for (int m = 0; m <= p; m++) {
    //             for (int l = 1; l <= k; l++) {
    //                 if (dp[i-1][j][l][m] == 2e18) continue;
    //                 int mask = (m+a[i][l] >= p) ? (1<<(l-1)) : 0;
    //                 dp[i][j | mask][l][m+a[i][l]] = min(dp[i-1][j][l][m] + c[i], dp[i][j | mask][l][m+a[i][l]]);
    //             }
    //         }
    //     }
    // }

    // ll ans = 2e18;
    // for (int i = p; i <= 10; i++) {
    //     for (int j = 1; j <= k; j++) {
    //         ans = min(ans, dp[n][(1<<k)-1][j][i]);
    //     }
    // }

    // if (ans == 2e18) cout << -1 << endl;
    // else cout << ans << endl;

    

    return 0;
}