#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    vector<int> x(5005), y(5005, 0);
    // vector<bool> c(5005, false);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> x.at(i);
    for (int i = 1; i <= m; i++) {
        int s, t;
        cin >> s >> t;
        y.at(s) = t;
    }

    vector<vector<ll>> dp(5005, vector<ll>(5005, -1));

    dp.at(0).at(0) = 0;
    dp.at(0).at(0) = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            dp.at(i).at(0) = max(dp.at(i-1).at(j), dp.at(i).at(0));
        }

        for (int j = 1; j <= n; j++) {
            if (i < j) continue;
            dp.at(i).at(j) = dp.at(i-1).at(j-1) + x.at(i) + y.at(j);
        }
    }

    ll ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, dp.at(n).at(i));

    cout << ans << endl;

    return 0;
}