#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;

ll modinv(ll a)
{
    ll ret = 1, y = MOD-2;

    while (y > 0) {
        if(y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

int main()
{
    string s;
    int n;

    cin >> s;
    n = (int)s.size();

    map<int, int> mp;
    vector<ll> fac(5005), invf(5005);
    
    fac.at(0) = fac.at(1) = 1;
    invf.at(0) = invf.at(1) = 1;

    for (int i = 2; i <= n; i++) {
        fac.at(i) = fac.at(i-1) * i % MOD;
        invf.at(i) = invf.at(i-1) * modinv(i) % MOD;
        // cout << fac.at(i) << " " << invf.at(i) << " " << fac.at(i) * invf.at(i) % MOD << endl; 
    }

    for (int i = 0; i < n; i++) mp[s.at(i) - 'a' + 1]++;

    vector<vector<ll>> dp(30, vector<ll>(5005, 0));

    dp.at(0).at(0) = 1;

    for (int i = 1; i <= 26; i++) {
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= min(j, mp[i]); k++) {
                if (j < k) continue;
                ll t = dp.at(i-1).at(j-k) * fac.at(j) % MOD;
                t = t * invf.at(j-k) % MOD;
                t = t * invf.at(k) % MOD;
                dp.at(i).at(j) += t;
                dp.at(i).at(j) %= MOD;
            }
        }
    }

    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        ans += dp.at(26).at(i);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}