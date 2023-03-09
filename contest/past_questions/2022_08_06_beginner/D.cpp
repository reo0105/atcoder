#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll l, r;
    cin >> n >> l >> r;

    vector<int> a(200005);
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    // ll ans = (ll)r*n;
    // ll suma = 0, sumb = 0, maxb = 0;

    // for (int i = 1; i <= n; i++) {
    //     suma += a.at(i);
    //     sumb += a.at(i) - l;
    //     maxb = max(maxb, sumb);
    //     ll now = suma + r*(n-i) - maxb;
    //     ans = min(ans, now);
    // }

    // cout << ans << endl;

    vector<vector<ll>> dp(200005, vector<ll>(3, 1LL<<58));

    for (int i = 0; i < 3; i++) dp.at(0).at(i) = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 3; j++) { //now 
            for (int k = 0; k < 3; k++) { //pre
                if (j < k) continue;
                if (j == 0) dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(k) + l);
                else if (j == 1) dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(k) + a.at(i));
                else dp.at(i).at(j) = min(dp.at(i).at(j), dp.at(i-1).at(k) + r);
            }
        }
    }

    ll ans = 1LL<<58;
    for (int i = 0; i < 3; i++) ans = min(ans, dp.at(n).at(i));
    cout << ans << endl;

    return 0;
}