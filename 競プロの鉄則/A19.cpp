#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, wei;
    vector<int> w(102), v(102);
    vector<vector<long long>> dp(105, vector<long long>(100005, -1));

    cin >> n >> wei;

    for (int i = 1; i <= n; i++) cin >> w.at(i) >> v.at(i);

    dp.at(0).at(0) = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= wei; j++) {
            if (j >= w.at(i)) dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i-1).at(j-w.at(i)) + v.at(i));
            else dp.at(i).at(j) = dp.at(i-1).at(j);
        }
    }

    long long ans = 0;

    for (int i = 1; i <= wei; i++) {
        ans = max(ans, dp.at(n).at(i));
    }

    cout << ans << endl;

    return 0;
}