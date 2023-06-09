#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

vector<ll> fac(3000005), inv(3000005);
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

ll nHr(ll n, ll r)
{

    ll ret = fac.at(n+r-1) * inv.at(r) % MOD;
    ret = ret * inv.at(n-1) % MOD;
    return ret;
}

int main()
{
    int r, g, b, k;
    cin >> r >> g >> b >> k;

    g -= k;
    r -= k;

    fac.at(0) = inv.at(0) = 1;
    fac.at(1) = inv.at(1) = 1;

    for (int i = 2; i <= 3000000; i++) {
        fac.at(i) = fac.at(i-1) * i % MOD;
        inv.at(i) = inv.at(i-1) * modpow(i, MOD-2) % MOD;
    }

    ll ans = fac.at(k+r+b) * inv.at(k) % MOD;
    ans = ans * inv.at(r) % MOD;
    ans = ans * inv.at(b) % MOD;
    ans = ans * nHr(k+b+1, g) % MOD;
    cout << ans << endl;

    return 0;
}