#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

vector<ll> fac(5005), finv(5005);

int modpow(ll x, ll y)
{
    ll res = 1;
    while (y > 0) {
        if (y & 1) res = res * x % MOD;
        x = x * x % MOD;
        y >>= 1;
    }

    return res;
}

void binom_init() 
{
    fac.at(0) = fac.at(1) = 1;
    finv.at(0) = finv.at(1) = 1;
    
    for(int i=2; i < 5005; i++){
        fac.at(i) = fac.at(i-1) * i%MOD;
        finv.at(i) = finv.at(i-1) * modpow(i, MOD-2) % MOD;
    }

    return;
}

ll binom(ll n, ll r)
{
    if(n < r || n < 0 || r < 0) return 0;
    
    return fac.at(n) * finv.at(r) % MOD * finv.at(n-r) % MOD;
}


int main()
{
    string s;
    binom_init();
    vector<int> cnt(30, 0);
    vector<vector<ll>> dp(30, vector<ll>(5005, 0));

    cin >> s;

    for (int i = 0; i < (int)s.size(); i++) {
        cnt.at(s.at(i) - 'a') += 1;
    }

    dp.at(0).at(0) = 1;

    for (int i = 0; i < 26; i++) {
        for (int j = 0; j <= (int)s.size(); j++) {
            for (int k = 0; k <= cnt.at(i); k++) {
                if (j >= k) dp.at(i+1).at(j) += dp.at(i).at(j-k) * binom(j,k);
                dp.at(i+1).at(j) %= MOD;
            }
        }
    }


    ll ans = 0;
    for (int i = 1; i <= (int)s.size(); i++) {
        ans += dp.at(26).at(i);
        ans %= MOD;
        // cout << dp.at(26).at(i) << endl;
    }

    cout << ans << endl;

    return 0;
}