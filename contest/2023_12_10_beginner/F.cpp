#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

typedef long long ll;
#define MOD 998244353

struct F {
    ll a, b;
    F(ll a = 1, ll b = 0): a(a), b(b) {}
};

ll op(ll a, ll b) { return (a+b) % MOD; }
ll e() { return 0; }

ll mapping(F f, ll x) {return ((f.a*x)%MOD + f.b) % MOD;}
F composition(F g, F f) {
    return F((f.a*g.a) % MOD, (g.b + (g.a*f.b)%MOD) % MOD);
}

F id() {return F(1, 0);}

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

int main()
{
    int n, m;
    cin >> n >> m;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    lazy_segtree<ll, op, e, F, mapping, composition, id> t(a);

    for (int i = 0; i < m; i++) {
        int l, r, x;
        cin >> l >> r >> x;
        l--;
        ll p = modpow(r-l, MOD-2);
        ll q = (1-p+MOD) % MOD;
        t.apply(l, r, F(q, p*x));
    }

    for (int i = 0; i < n; i++) {
        ll ans = t.get(i);
        cout << ans << " ";
    }
    cout << endl;

    return 0;
}