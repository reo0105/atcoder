#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;
typedef long long ll;
#define MOD 998244353

ll modinv(ll a, ll y)
{
    ll ret = 1;

    while(y > 0) {
        if (y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

int main()
{
    int n;

    fenwick_tree<int> fnum(200005);
    fenwick_tree<ll> fsum(200005);

    cin >> n;
    ll p = 0, q = 1;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        p += (fnum.sum(1, a) * (ll)a + fsum.sum(a, 200004)) * 2 + a;

        fnum.add(a, 1);
        fsum.add(a, a);
        
        q = (ll)(i+1) * (i+1) % MOD;
        p %= MOD;

        ll ans = modinv(q, MOD-2);
        ans = ans * p % MOD;
        cout << ans << endl;
    }


}