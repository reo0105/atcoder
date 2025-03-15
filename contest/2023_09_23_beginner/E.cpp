#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve() {
    ll n, x, k;
    cin >> n >> x >> k;

    auto f = [&](ll v, ll d) -> ll {
        if (v > n) return 0;
        ll l = v, r = v;
        for (int i = 0; i < d; i++) {
            l <<= 1;
            r = r<<1|1;
            if (l > n) return 0;
        }
        r = min(r, n);
        return r-l+1;
    };

    ll ans = f(x, k);
    while (x > 1 && k >= 2) {
        ans += f(x^1, k-2);
        k--; x >>= 1;
    }
    if (k == 1 && x != 1) ans++;
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) solve();
    
    return 0;
}