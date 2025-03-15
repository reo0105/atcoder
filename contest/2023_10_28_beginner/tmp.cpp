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
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 0; i < n; i++) cin >> a[i+1];

    vector<ll> dp(n+1);
    ll inv_n = modinv(n);
    ll sum = 0;

    for (int i = n; i >= 0; i--) {
        dp[i] = sum * inv_n + a[i];
        dp[i] %= MOD;
        sum += dp[i];
        sum %= MOD;
    }

    cout << dp[0] << endl;

    return 0;
}
