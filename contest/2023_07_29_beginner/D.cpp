#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

int main()
{
    string s;
    cin >> s;

    ll ans = 0;

    int n = (int)s.size();

    vector<vector<ll>> dp(n+1, vector<ll>(n+1, 0));

    dp[0][0] = 1;
    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            for (int j = 1; j < n; j++) {
                dp[i+1][j-1] = dp[i][j];
            }
        } else if (s[i] == '(') {
            for (int j = 0; j < n; j++) {
                dp[i+1][j+1] = dp[i][j];
            }
        } else {
            for (int j = 0; j < n; j++) {
                dp[i+1][j+1] = dp[i][j];
                if (j != 0) {
                    dp[i+1][j-1] += dp[i][j];
                    dp[i+1][j-1] %= MOD;
                }
            } 
        }
    }

    cout << dp[n][0] << endl;

    return 0;
}