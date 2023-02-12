#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;

int main()
{
    int n;
    ll x = 2, y = 7;
    cin >> n;

    vector<vector<ll>> dp(1000005, vector<ll>(10, 0));

    for (int i = 1; i <= 9; i++) dp.at(1).at(i) = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= 9; j++) {
            if (j == 1) dp.at(i).at(j) += dp.at(i-1).at(j) + dp.at(i-1).at(j+1);
            else if (j == 9) dp.at(i).at(j) += dp.at(i-1).at(j) + dp.at(i-1).at(j-1);
            else dp.at(i).at(j) += dp.at(i-1).at(j-1) + dp.at(i-1).at(j) + dp.at(i-1).at(j+1);
            dp.at(i).at(j) %= MOD;
        }
    }    

    ll ans = 0;
    for (int i = 1; i <= 9; i++) ans += dp.at(n).at(i);

    cout << ans%MOD << endl;

    return 0;
}