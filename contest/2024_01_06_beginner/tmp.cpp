#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define D 400
#define MOD 998244353

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    const ll inf = 1e18;

    vector<ll> dp(n, 0);
    vector<vector<ll>> dp2(D, vector<ll>(n, 0));

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < D; j++) {
            dp[i] += dp2[j][i];
            dp[i] %= MOD;
            if (i+j < n) {
                dp2[j][i+j] += dp2[j][i];
                dp2[j][i+j] %= MOD;
            }
        }

        if (a[i] < D) {
            if (i+a[i] < n) {
                dp2[a[i]][i+a[i]] += dp[i];
                dp2[a[i]][i+a[i]] %= MOD;
            }
        } else {
            for (int j = i+a[i]; j < n; j += a[i]) {
                if (j < n) {
                    dp[j] += dp[i];
                    dp[j] %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}