#include <bits/stdc++.h>
using namespace std;

#define INF 1e13
typedef pair<int, int> pii;

double dist(double px, double py, double nx, double ny)
{
    return sqrt((px - nx) * (px - nx) + (py - ny) * (py - ny));
}

int main()
{
    int n;
    vector<pii> xy;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        xy.emplace_back(x, y);
    }

    vector<vector<double>> dp(10005, vector<double>(40, INF));

    dp[1][0] = 0;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 30; j++) {
            for (int ni = i+1; ni <= n; ni++) {
                int skip = ni-i-1;
                int nj = j + skip;
                if (nj > 30) break;
                dp[ni][nj] = min(dp[i][j] + dist(xy[i-1].first, xy[i-1].second, xy[ni-1].first, xy[ni-1].second), dp[ni][nj]);
            }
        }
    }

    double ans = INF;
    for (int i = 0; i < 30; i++) {
        ans = min(ans, dp[n][i]+(1<<i>>1));
    }

    cout << fixed << setprecision(12) << ans << endl;
}