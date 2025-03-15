#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
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

int main()
{
    int n;
    cin >> n;

    int m = 10;
    int m2 = 1<<(m+1);

    vector<ll> dp(m2);
    dp[1] = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        vector<ll> p(m2);
        swap(dp, p);
        ll inv_a = modpow(a, MOD-2);
        for (int s = 0; s < m2; s++) {
            p[s] *= inv_a;
            p[s] %= MOD;
            for (int j = 1; j <= min(m, a); j++) {
                dp[(s|s<<j)&(m2-1)] += p[s];
                dp[(s|s<<j)&(m2-1)] %= MOD;
            }
            dp[s] += p[s] * max(0, a-m);
            dp[s] %= MOD;
        }
    }
    
    ll ans = 0;
    for (int s = 0; s < m2; s++) {
        if (s>>m&1) {
            ans += dp[s];
            ans %= MOD;
        }
    }

    cout << ans << endl;

    return 0;
}