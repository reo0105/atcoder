#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;
#define MOD 998244353

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                s[i+1][j] = '#';
                if (j+1 < m) s[i+1][j+1] = '#';
            }
        }
    }

    vector<vector<ll>> dp(n+2, vector<ll>(m+1));

    dp[0][m] = 1;
    for (int j = m; j >= 0; j--) {
        for (int i = 0; i < n+2; i++) {
            if (i+1 < n+2) {
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }
            if (i-1 >= 0 && j-1 >= 0) {
                if (i == 1 || s[i-2][j-1] == '.') {
                    dp[i-1][j-1] += dp[i][j];
                    dp[i-1][j-1] %= MOD;
                }
            }
        }
    }

    cout << dp[n+1][0] << endl;

    return 0;
}