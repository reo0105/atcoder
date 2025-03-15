#include <bits/stdc++.h>
using namespace std;

struct edge {
    int to, b, c;
};

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<edge>> g(n);

    for (int i = 0; i < m; i++) {
        int u, v, b, c;
        cin >> u >> v >> b >> c;
        u--; v--;
        g[u].push_back((edge){v, b, c});
    }

    auto f = [&](double x) {
        const double INF = 1e18;
        vector<double> dp(n, -INF);
        dp[0] = 0;
        for (int i = 0; i < n; i++) {
            for (auto e : g[i]) {
                dp[e.to] = max(dp[e.to], dp[i]+e.b-e.c*x);
            }
        }

        return dp[n-1] >= 0;
    };

    double l = 0, r = 1e4;

    for (int i = 0; i < 50; i++) {
        double mid = (l + r) / 2;
        if (f(mid)) l = mid;
        else r = mid;
    }

    cout << setprecision(12) << l << endl;

}