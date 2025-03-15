#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

#define MOD 998244353

ll modpow(ll a, ll y) {
    ll ret = 1;

    while (y > 0) {
        if (y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

ll modinv(ll x) {
    return modpow(x, MOD-2);
}

int main() {
    int n, x;
    cin >> n >> x;

    vector<int> t(n);
    for (int i = 0; i < n; i++) cin >> t[i];

    vector<ll> dp(10005, 0);

    ll inv_n = modinv(n);
    dp[0] = 1;

    for (int i = 0; i <= x; i++) {
        for (int j = 0; j < n; j++) {
            if (i >= t[j]) dp[i] += dp[i-t[j]] * inv_n;
            dp[i] %= MOD;
        }
    }

    ll ans = 0;
    for (int i = max(0, x-t[0]+1); i <= x; i++) {
        ans += dp[i] * inv_n;
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}