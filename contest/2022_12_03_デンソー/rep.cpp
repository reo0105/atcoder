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

int main()
{
    int n, p;
    cin >> n >> p;

    ll one = (100 - p) * modinv(100) % MOD;
    ll two = p * modinv(100) % MOD;

    vector<ll> dp(200005, 0);

    dp.at(1) = 1;

    for (int i = 2; i <= n; i++) {
        dp.at(i) = (dp.at(i-1) * one + dp.at(i-2) * two + 1) % MOD;
    }

    cout << dp.at(n) << endl;
}