#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        ll ans = 0;
        cin >> n;

        // x <= y <= zを仮定
        //すべて同じ場合 (x = y = z)
        for (int z = 1; (ll)z*z <= n; z++) {
            ans++;
            ans %= mod;
        }

        //2つが同じ場合 (x < y = z)
        for (int z = 1; (ll)z*z <= n; z++) {
            ans += (z-1) * 3;
            ans %= MOD;
        }

        //すべて異なる場合 (x < y < z)
        for (int z = 1; (ll)z*z <= n; z++) {
            ans += z-1;
            ans %= MOD;
        }
    }
}