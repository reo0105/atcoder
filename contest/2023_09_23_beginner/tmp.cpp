#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int main() {
    int q, k;
    cin >> q >> k;

    vector<ll> dp(k+1);
    dp[0] = 1;

    for (int qi = 0; qi < q; qi++) {
        char c; int x;
        cin >> c >> x;
        if (c == '+') {
            for (int i = k; i >= x; i--) {
                dp[i] += dp[i-x];
                dp[i] %= MOD;
            }
        } else {
            for (int i = x; i <= k; i++) {
                dp[i] -= dp[i-x];
                dp[i] = (dp[i] + MOD) % MOD;
            }
        }
        cout << dp[k] << endl;
    }    



    return 0; 
}