#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

typedef long long ll;

ll op(ll x, ll y) { return max(x, y); }
ll e() { return -1e18; }

int main() {
    int n;
    ll c;
    cin >> n >> c;

    int m;
    cin >> m;

    segtree<ll, op, e> tl(n), tr(n);

    tl.set(0, 0);
    tr.set(0, 0);

    ll ans = 0;
    vector<ll> t(m), p(m);
    for (int i = 0; i < m; i++) {
        cin >> t[i] >> p[i];
        t[i]--;
        ll now = -1e18;

        now = max(now, tl.prod(0, t[i])-c*t[i]);
        now = max(now, tr.prod(t[i], n)+c*t[i]);

        now += p[i];
        tl.set(t[i], now+c*t[i]);
        tr.set(t[i], now-c*t[i]);

        ans = max(ans, now);
    }
    cout << ans << endl;

    return 0;
}