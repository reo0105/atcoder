#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += (ll)a[i]*i;
        ans %= MOD;
    }

    vector<ll> b(n);
    for (int i = 0; i < n; i++) {
        b[i] = 1;
        ll x = a[i];
        while (x) {
            b[i] *= 10;
            b[i] %= MOD;
            x /= 10;
        }
    }

    ll t = 0;
    for (int i = n-1; i >= 0; i--) {
        ans += t*a[i];
        t += b[i];
        t %= MOD;
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}