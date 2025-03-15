#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    int n;
    vector<int> t(100005), x(100005), a(100005);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> t.at(i) >> x.at(i) >> a.at(i);

    vector<vector<ll>> dp(100005, vector<ll>(6, 0));

    int now = 1;
    for (int i = 1; i <= t.at(n); i++) {
        for (int j = 0; j < 5; j++) { //now
            if (i < j) continue;
            for (int k = 0; k < 5; k++) {
                if (abs(j-k) > 1) continue;

                dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(k));
                // cout << i << " " << j << " "  << k << " " << dp.at(i).at(j) << endl; 
            }
            if (t.at(now) == i && j == x.at(now)) {
                dp.at(i).at(j) += a.at(now);
            } 
        }
        if (t.at(now) == i) now++;
    }

    // for (int i = 1; i <= t.at(n); i++) {
    //     for (int j = 0; j < 5; j++) {
    //         cout << dp.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    for (int i = 0; i < 5; i++) ans = max(ans, dp.at(t.at(n)).at(i));

    cout << ans << endl;

    return 0;
}