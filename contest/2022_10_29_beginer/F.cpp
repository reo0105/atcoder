#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(3005);
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<vector<vector<int>>> dp(3005, vector<vector<int>>(3005, vector<int>(2, 3000)));

    dp.at(0).at(0).at(0) = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            for (int k = 0; k < 2; k++) { //0 使う, 1使わない  0->1で+1
                // if (j >= a.at(i) && dp.at(i-1).at(j-a.at(i)).at(k) != 3000) {
                if (j >= a.at(i)) dp.at(i).at(j).at(0) = min(dp.at(i-1).at(j-a.at(i)).at(k), dp.at(i).at(j).at(0));
                dp.at(i).at(j).at(1) = min(dp.at(i-1).at(j).at(k) + (k==0 ? 1 : 0), dp.at(i).at(j).at(1));
                // }
            }
        }
    }

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp.at(i).at(j).at(0) << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    // for (int i = 0; i <= n; i++) {
    //     for (int j = 0; j <= m; j++) {
    //         cout << dp.at(i).at(j).at(1) << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;

    for (int i = 1; i <= m; i++) {
        int ans = min(dp.at(n).at(i).at(0), dp.at(n).at(i).at(1));
        if (ans == 3000) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}