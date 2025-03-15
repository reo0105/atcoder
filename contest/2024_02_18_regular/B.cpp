#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353

typedef long long ll;

vector<ll> fac(500005, 1);
vector<ll> inv(500005, 1);

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

void init()
{
    for (int i = 1; i <= 500001; i++) {
        fac.at(i) = fac.at(i-1) * i % MOD;
        inv.at(i) = inv.at(i-1) * modinv(i) % MOD;
    }
}

ll nCr(ll n, ll r)
{
    if (n < r) return 0;
    ll t = fac.at(n) * inv.at(r) % MOD;
    return t * inv.at(n-r) % MOD;
}

int main()
{
    int n, k, l;
    cin >> n >> k >> l;

    init();

    ll ans = 1;
    int rap = n-k;

    for (int i = 0; i < n; i++) {
        if (i < rap) {
            ans *= (l-i);
            ans %= MOD;
        } else {
            ans *= (l-rap);
            ans %= MOD;
        }
    }

    cout << ans << endl;


    return 0;
}