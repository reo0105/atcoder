#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int main()
{
    int q, k;
    cin >> q >> k;

    vector<ll> dp(5005, 0);
    // vector<ll> p(5005, 0);
    // p[0] = 1;
    dp[0] = 1;
    
    for (int i = 0; i < q; i++) {
        char s;
        int x;
        cin >> s >> x;

        if (s == '+') {
            for (int j = k; j >= 0; j--) {
                if (j >= x) dp[j] = (dp[j] + dp[j-x]) % MOD;
                else dp[j] = dp[j];
            }
        } else {
            for (int j = 0; j <= k; j++) {
                if (j >= x) dp[j] = (dp[j] - dp[j-x] + MOD) % MOD;
                else dp[j] = dp[j];
            }
        }

        cout << dp[k] << endl;
        // swap(dp, p);
    }
    
    return 0;
}