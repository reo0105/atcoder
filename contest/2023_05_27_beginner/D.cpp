#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    string s;
    cin >> s;

    int n = (int)s.size();

    ll ans = 0;
    vector<vector<ll>> dp(300005, vector<ll>(2, 0));

    dp.at(0).at(1) = z;

    for (int i = 1; i <= n; i++) {
        // for (int j = 0; j < 1; j++) {
        if (s.at(i-1) == 'a') {
            dp.at(i).at(0) = min(dp.at(i-1).at(0)+x, dp.at(i-1).at(1)+y+z);
            dp.at(i).at(1) = min(dp.at(i-1).at(1)+y, dp.at(i-1).at(0)+x+z);
        } else {
            dp.at(i).at(0) = min(dp.at(i-1).at(0)+y, dp.at(i-1).at(1)+x+z);
            dp.at(i).at(1) = min(dp.at(i-1).at(1)+x, dp.at(i-1).at(0)+y+z);
        }
        // }
    }

    cout << min(dp.at(n).at(0), dp.at(n).at(1)) << endl;

    return 0;
}