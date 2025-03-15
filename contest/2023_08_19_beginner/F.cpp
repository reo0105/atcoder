#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {

    int n;
    cin >> n;

    vector<int> x(n+1), y(n+1);
    for (int i = 1; i <= n; i++) cin >> x[i] >> y[i];

    const double INF = 1e18;
    vector<vector<double>> dp(n+1, vector<double>(60, INF));

    auto dist = [&](int xi, int xj, int yi, int yj) -> double {
        return sqrt((xi - xj) * (xi - xj) + (yi - yj) * (yi - yj));
    };

    dp[1][0] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 30; j++) {
            for (int ni = i+1; ni <= n; ni++) {
                int nj = j+ni-i-1;
                if (nj > 30) continue;
                dp[ni][nj] = min(dp[ni][nj], dp[i][j]+dist(x[i], x[ni], y[i], y[ni]));
            }
        }
    }

    double ans = INF;
    for (int i = 0; i < 50; i++) {
        ans = min(ans, dp[n][i]+(1LL<<i>>1));
    }

    cout << setprecision(12) << ans << endl;

    return 0;
}