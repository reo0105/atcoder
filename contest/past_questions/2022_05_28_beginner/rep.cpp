#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> dp(1005, vector<ll>(5005, 0));
    vector<ll> sum(5005, 0);

    if (k == 0) {
        ll ans = 1;
        for (int i = 1; i <= n; i++) {
            ans *= m;
            ans %= MOD;
        }
        cout << ans << endl;
        return 0;
    }

    for (int i = 1; i <= m; i++) dp.at(1).at(i) = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            sum.at(j) = sum.at(j-1) + dp.at(i-1).at(j);
            sum.at(j) %= MOD;
        }

        for (int j = 1; j <= m; j++) {
            dp.at(i).at(j) = (sum.at(max(j-k, 0)) - sum.at(0) + MOD) % MOD;
            dp.at(i).at(j) += sum.at(m) - sum.at(min(j+k-1, m)) + MOD;
            dp.at(i).at(j) %= MOD;
        }
    }

    ll ans = 0;
    for (int i = 1; i <= m; i++) {
        ans += dp.at(n).at(i);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}