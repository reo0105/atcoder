#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main()
{
    int n;
    vector<int> x(300005), y(300005);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x.at(i) >> y.at(i);

    vector<vector<ll>> dp(300005, vector<ll>(2, -INF));

    dp.at(0).at(0) = 0;

    for (int i = 1; i <= n; i++) {
        if (x.at(i) == 0) {
            dp.at(i).at(0) = max(dp.at(i-1).at(0), dp.at(i-1).at(0) + y.at(i));
            dp.at(i).at(0) = max(dp.at(i).at(0), dp.at(i-1).at(1) + y.at(i));
            dp.at(i).at(1) = dp.at(i-1).at(1);
        } else if (x.at(i) == 1) {
            dp.at(i).at(0) = dp.at(i-1).at(0);
            dp.at(i).at(1) = max(dp.at(i-1).at(0) + y.at(i), dp.at(i-1).at(1));
        }
    }

    cout << max(dp.at(n).at(0), dp.at(n).at(1)) << endl;

    return 0;
}