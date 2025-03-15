#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int n;
    cin >> n;

    vector<int> p(n+1);
    for (int i = 1; i <= n; i++) cin >> p[i];

    vector<vector<double>> dp(5005, vector<double>(5005, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] * 0.9 + p[i]);
        }
    }

    double ans = -1e9;
    double sum_denomitor = 1;
    double denomitor = 1;
    for (int k = 1; k <= n; k++) {
        ans = max(ans, dp[n][k] / sum_denomitor - 1200 / sqrt(k));
        denomitor *= 0.9;
        sum_denomitor += denomitor;
    }

    cout << setprecision(12) << ans << endl;
    
    return 0;
}