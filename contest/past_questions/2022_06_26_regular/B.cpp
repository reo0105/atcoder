#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353


ll modpow(ll a, ll x)
{
    ll ret = 1;
    while (x > 0) {
        if (x & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        x >>= 1;
    }
    return ret;
}


int main()
{
    int n;
    cin >> n;

    vector<ll> fac(250005, 1);
    vector<ll> inv(250005, 1);

    for (int i = 2; i <= n*n; i++) {
        fac.at(i) = fac.at(i-1) * i;
        fac.at(i) %= MOD;
        inv.at(i) = inv.at(i-1) * modpow(i, MOD-2);
        inv.at(i) %= MOD;
        // cout << fac.at(i) * inv.at(i) % MOD << endl;
    }

    ll ans = 1;
    ll ng = 0;

    for (int i = 1; i <= n*n; i++) {
        ans *= i;
        ans %= MOD;
    }

    ll t = 0;
    t = fac.at(n*n) * inv.at(2*n-1);
    t %= MOD;
    t *= inv.at(n*n-2*n+1);
    t %= MOD;
    t *= fac.at(n-1);
    t %= MOD;
    t *= fac.at(n-1);
    t %= MOD;
    t *= fac.at((n-1)*(n-1));
    t %= MOD;
    t *= n*n;
    t %= MOD;
    ng += t;
    ng %= MOD;
        // if (i >= n) {
        //     ng += fac.at(i-1) * inv.at(i-n);
        //     ng %= MOD;
        // }

    // cout << ng << endl;
    cout << (ans - ng + MOD) % MOD << endl;

    return 0;
}