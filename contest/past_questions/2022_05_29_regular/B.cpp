#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353 


int main()
{
    ll n, m;
    ll ans = 0;
    int dig = 0;
    cin >> n >> m;

    while((m>>dig) > 0) {
        dig++;
    }

    ll tmp = 1;
    ll two = 1;
    int cnt = 0;
    while((m>>cnt) > 0) {
        if (((m>>cnt)&1) == 1) {
            tmp += two;
        }
        two <<= 1;
        cnt++;
    }

    two >>= 1;
    tmp -= two;
    // cout << tmp << endl;

    vector<ll> add(65, 1);
    for (int i = 1; i <= dig; i++) {
        add.at(i) = (1LL << i) - (1LL << (i-1));
        add.at(i) %= MOD;
    }
    add.at(dig) = tmp % MOD;

    if (dig < n) cout << 0 << endl;
    else {
        vector<vector<ll>> dp(65, vector<ll>(65, 0));
        for (int i = 1; i <= dig; i++) dp.at(1).at(i) = add.at(i);
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j <= dig; j++) { //now
                for (int k = 1; k <= dig; k++) { //pre
                    if (j <= k) continue;
                    dp.at(i).at(j) += dp.at(i-1).at(k) * add.at(j);
                    dp.at(i).at(j) %= MOD;
                    // cout << i << " " << j << " " << k << endl;
                }
            }
        }

        ll ans = 0;
        // for (int j = 0; j <= n; j++){
        for (int i = 0; i <= dig; i++) {
            // cout << dp.at(n).at(i) << " ";
            ans += dp.at(n).at(i);
            ans %= MOD;
        }
        // cout << endl;
        // }
        cout << ans << endl;
    }
    
    return 0;
}