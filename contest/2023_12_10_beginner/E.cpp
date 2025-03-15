#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, d;
    cin >> n >> d;

    vector<double> w(n);
    for (int i = 0; i < n; i++) cin >> w[i];

    double xm = 0;
    for (int i = 0; i < n; i++) xm += w[i];
    xm /= d;

    vector<double> sum_w(100000, 0);

    for (int s = 0; s < (1<<n); s++) {
        double sum = 0;
        for (int i = 0; i < n; i++) {
            if ((s >> i) & 1) sum += w[i];
        }
        sum_w[s] = (sum - xm) * (sum - xm) / d;
    }

    const double inf = 1e18;
    vector<vector<double>> dp(20, vector<double>(100000, inf));

    dp[0][(1<<n)-1] = 0;

    for (int i = 0; i < d; i++) {
        for (int s = 0; s < (1<<n); s++) {
            for (int t = s;; t = (t-1) & s) {
                if (dp[i+1][s^t] > dp[i][s] + sum_w[t]) {
                    dp[i+1][s^t] = dp[i][s] + sum_w[t];
                }
                if (t == 0) break;
            }
        }
    } 

    double ans = dp[d][0];
    cout << setprecision(14) << ans << endl;

    return 0;
}