#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

ll modpow(ll a, ll y)
{
    ll ret = 1;

    while (y > 0) {
        if (y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

ll modinv(ll y)
{
    return modpow(y, MOD-2);
}

int main()
{
    int n;
    cin >> n;

    ll inv_tow = modinv(2);

    vector<ll> pa(n+1, 1);
    for (int i = 0; i < n; i++) {
        pa[i+1] = pa[i] * inv_tow;
        pa[i+1] %= MOD;
    }

    /*i人残っている状態から前からj番目が生き残る確率*/
    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));

    dp[1][0] = 1;
    for (int k = 2; k <= n; k++) {
        ll x = (2 - pa[k-1] + MOD) % MOD;
        x = modinv(x);

        for (int i = 0; i < k-1; i++) {
            dp[k][0] += pa[k-1-i] * dp[k-1][i];
            dp[k][0] %= MOD;
        }

        for (int i = 0; i < k-1; i++) {
            ll now = dp[k][i];
            now = (now - (dp[k-1][i] * pa[k-1] % MOD) + MOD) % MOD;
            now = now * inv_tow % MOD;
            now = (now + dp[k-1][i]) % MOD;
            dp[k][i+1] = now;
        }

        for (int i = 0; i < k; i++) {
            dp[k][i] = dp[k][i] * x % MOD;
        }
    }

    for (int i = 0; i < n; i++) cout << dp[n][i] << " ";
    cout << endl;

    return 0;
}