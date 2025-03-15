#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int main() {
    ll n, m;
    cin >> n >> m;

    ll ans = 0;
    n++;

    for (int i = 0; i < 60; i++) {
        if (((m >> i) & 1) == 0) continue;

        ll p = 2LL << i;
        ll rem = n % p;

        ans += n / p * (1LL<<i);
        ans %= MOD;
        ans += (rem <= (1LL<<i)) ? 0 : rem - (1LL<<i);
        ans %= MOD;
        // cout << ans << " ";
    }
    // cout << endl;

    cout << ans << endl;

    return 0;
}