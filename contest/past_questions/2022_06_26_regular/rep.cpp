#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

ll modpow(ll x)
{
    ll ret = 1;
    ll y = MOD-2;

    while (y > 0) {
        if (y & 1) ret = ret * x % MOD;
        x = x * x % MOD;
        y >>= 1;
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
        fac.at(i) = fac.at(i-1)*i % MOD;
        inv.at(i) = inv.at(i-1) * modpow(i) % MOD;
    }


    ll ans = fac.at(n*n);

    ll ng = fac.at(n*n) * inv.at(n*2-1) % MOD;
    ng = ng * inv.at(n*n-2*n+1) % MOD;
    ng = ng * fac.at(n-1) % MOD;
    ng = ng * fac.at(n-1) % MOD;
    ng = ng * fac.at(n*n-2*n+1) % MOD;
    ng = ng * n * n % MOD;

    cout << (ans - ng + MOD) % MOD << endl;

    return 0;
}