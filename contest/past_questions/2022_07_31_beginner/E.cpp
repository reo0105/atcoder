#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;

vector<ll> fac(200005, 1);
vector<ll> inv(200005, 1);

ll modinv(ll a)
{
    ll ret = 1, y = MOD - 2;

    while (y > 0) {
        if (y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

void init()
{
    for (int i = 1; i <= 200001; i++) {
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
    int n, m, k;
    cin >> n >> m >> k;

    init();

    vector<int> d(200005, 0);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        d.at(u)++; d.at(v)++;
    }

    int odd = 0, even = 0;
    for (int i = 1; i <= n; i++) {
        if (d.at(i) % 2 == 0) even++;
        else odd++;
    }

    ll ans = 0;
    for (int i = 0; i <= k / 2 * 2; i += 2) {
        ll t = nCr(odd, i) * nCr(even, k-i) % MOD;
        ans += t;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}