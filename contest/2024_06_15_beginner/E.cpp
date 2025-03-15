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

ll modinv(ll x)
{
    return modpow(x, MOD-2);
}

ll nCr(int n, int r, vector<ll> &fact, vector<ll> &ifact)
{
    ll ret = fact[n];
    ret = ret * ifact[r] % MOD;
    ret = ret * ifact[n-r] % MOD;
    return ret;
}

int main()
{
    int n = 26;
    int k;
    cin >> k;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    vector<ll> dp(k+1);
    dp[0] = 1;

    vector<ll> fact(1005, 0);
    vector<ll> ifact(1005, 0);

    fact[0] = fact[1] = 1;
    for (int i = 2; i <= 1002; i++) {
        fact[i] = fact[i-1] * i % MOD; 
    }

    ifact[0] = ifact[1] = 1;
    for (int i = 2; i <= 1002; i++) {
        ifact[i] = modinv(fact[i]); 
    }

    for (int i = 0; i < n; i++) {
        vector<ll> old(k+1);
        swap(old, dp);

        for (int j = 0; j <= k; j++) {
            for (int a = 0; a <= c[i]; a++) {
                int nj = j + a;
                if (nj > k) break;
                dp[nj] += old[j] * nCr(nj, a, fact, ifact) % MOD;
                dp[nj] %= MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += dp[i];
        ans %= MOD;
    }

    cout << ans << endl;
    return 0;
}