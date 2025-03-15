#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    int D = sqrt(n);

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> s(D, vector<ll>(n));
    vector<ll> dp(n);

    dp[0] = 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < D; j++) {
            dp[i] += s[j][i]; 
            dp[i] %= MOD;
            if (i+j < n) {
                s[j][i+j] += s[j][i];
                s[j][i+j] %= MOD;
            }
        }
        if (a[i] < D) {
            if (i+a[i] < n) {
                s[a[i]][i+a[i]] += dp[i];
                s[a[i]][i+a[i]] %= MOD;
            }
        } else {
            for (int j = i+a[i]; j < n; j += a[i]) {
                dp[j] += dp[i];
                dp[j] %= MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans << endl;
    
}