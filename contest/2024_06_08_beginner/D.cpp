#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

ll modpow (ll a, ll y)
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

int main() {
    ll n;
    cin >> n;

    ll keta = 1;
    ll temp = n;

    while (temp) {
        keta *= 10;
        temp /= 10;
        keta %= MOD;
    }

    ll s = ((modpow(keta, n) - 1) + MOD) % MOD;
    s *= modinv(keta-1);
    s %= MOD;
    n %= MOD;
    s *= n;
    s %= MOD;
    cout << s << endl;

    return 0;
}