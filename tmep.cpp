#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    vector<double> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] /= (double)100;
    }

    vector<vector<double>> dp(n+1, vector<double>(n+1));

    for (int i = 0; i <= n; i++) dp[i][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i+1 < j) continue;
            dp[i+1][j] = dp[i][j-1] * p[i];
            dp[i+1][j] += dp[i][j] * (1-p[i]);
        }
    }

    for (int i = 1; i <= n; i++) cout << dp[n][i] << " ";
    cout << endl;

    vector<double> dp2(x+1);

    dp2[0] = 1;
    for (int i = x-1; i >= 0; i--) {
        for (int j = 1; j <= n; j++) {
            if (i+j <= x) dp2[i] += dp2[i+j] * dp[n][j];
        }
    }

    cout << fixed << setprecision(12) << dp2[0] << endl;

    return 0;
}