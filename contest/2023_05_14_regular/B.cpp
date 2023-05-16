#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

vector<ll> divisor(ll n) {
    vector<ll> ret;
    for (ll i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end()); // 昇順に並べる
    return ret;
}

int main()
{
    int t;
    ll ans = 0;

    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        // vector<ll> div = divisor(n);
        // cout << div.size() << endl;

        for (int x = 1; x * x <= n; x++) {
            int lim = n / x;
            for (int y = x; y * y <= lim; y++) {
                if (x*y > n) break;
                int z = n/y;
                if (z <= lim) {
                    if (x == y || y == z || z == x) ans += (z-1)*3+1;
                    else if (x == y && y == z) ans += z;
                    else ans += z*6;
                    ans %= MOD;
                }
            }
        }

        cout << ans << endl;
    }


    return 0;
}