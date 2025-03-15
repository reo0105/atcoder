#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> p(n+1);
    vector<double> coef(n+1, 1);

    double nine = 0.9;
    for (int i = 2; i <= n; i++) {
        coef[i] = coef[i-1] + nine;
        nine *= 0.9;
    }

    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<vector<double>> dp(n+1, vector<double> (n+1, 0));

    for (int i = 1; i <= n; i++) {
        for (int k = 1; k <= i; k++) {
            double temp = dp[i-1][k-1] * 0.9 + p[i];
            dp[i][k] = max(dp[i-1][k], temp);
        }
    }

    double ans = -1e9;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, dp[n][i] / coef[i] - 1200 / sqrt(i));
    }

    cout << fixed << setprecision(12)  << ans << endl;

    return 0;
}