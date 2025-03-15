#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353


int main()
{
    int t;
    ll ans = 0;

    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        // x <= y <= z
        for (ll y = 1; y * y <= n; y++) {
            ll x = y; //xとして取れる最大値
            ll z = n/y; //zとして取れる最大値

            // cout << x << " " << y << " " << z << endl;

            // x < y < z
            ans = (ans + (x-1)*(z-y)*6) % MOD;
            // x = y < z
            ans = (ans + (z-y)*3) % MOD;
            // x < y = z
            ans = (ans + (x-1)*3) % MOD;
            // x = y = z
            ans = (ans + 1) % MOD;
        }

        cout << ans << endl;
        ans = 0;
    }


    return 0;
}