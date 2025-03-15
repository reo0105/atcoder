#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> c(n+1), p(n+1);
    vector<vector<int>> s(n+1);

    for (int i = 1; i <= n; i++) {
        cin >> c[i] >> p[i];
        for (int j = 0; j < p[i]; j++) {
            int t;
            cin >> t;
            s[i].push_back(t);
        }
    }

    const double INF = 1e18;
    vector<double> dp(105, INF);

    dp[0] = 0.0;
    for (int i = 1; i <= m; i++) {
        double mini = INF;
        for (int j = 1; j <= n; j++) {
            double t = 0;
            int cnt = p[j];
            for (int k = 0; k < p[j]; k++) {
                if (i >= s[j][k] && s[j][k] != 0) t += dp[i-s[j][k]];
                else if (s[j][k] == 0) cnt--;
            }
            t /= (double)p[j];
            t += c[j];
            if (cnt != 0) t = t * p[j] / (double)cnt;
            // if (i == 1) cout << t << " ";
            mini = min(mini, t);
        }
        dp[i] = mini;
    }
    // cout << endl;
    // for (int i = 0; i <= m; i++) cout << dp[i] << " ";
    // cout << endl;
    cout << setprecision(12) << dp[m] << endl;

    return 0;
}