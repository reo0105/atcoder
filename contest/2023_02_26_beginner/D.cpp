#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;

int main()
{
    int n;
    vector<vector<int>> a(200005, vector<int>(2, 0));//, b(200005);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 2; j++) {
            cin >> a.at(i).at(j);
        }
    }

    // sort(c.begin(), c.end());

    vector<vector<ll>> dp(200005, vector<ll>(2, 0));

    dp.at(0).at(0) = 1;
    dp.at(0).at(1) = 1;

    for (int i = 1; i < n; i++) {
        for (int j = 0; j < 2; j++) { //now
            for (int k = 0; k < 2; k++) { //pre
                if (a.at(i-1).at(k) == a.at(i).at(j)) continue;

                // cout << i << " " << j <<" " << k << endl;
                dp.at(i).at(j) += dp.at(i-1).at(k);
                dp.at(i).at(j) %= MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 2; i++) ans += dp.at(n-1).at(i);
    // ans /= 2;
    cout << ans % MOD << endl;

    return 0;
}