#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353
#include <atcoder/all>
using namespace atcoder;
using mint = modint998244353;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> dp(1005, vector<ll>(5005, 0));
    vector<ll> cnt(5005, 0);
    if (k == 0) {
        mint ans = mint(m).pow(n);
        cout << ans.val() << endl;
        return 0;
    }

    for (int j = 0; j <= m; j++) dp.at(1).at(j) = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cnt.at(j) = (cnt.at(j-1) + dp.at(i-1).at(j-1)) % MOD;
        }

        auto sum = [&](int l, int r) -> ll {
            if (l > r) return 0;
            return (cnt.at(r+1) - cnt.at(l) + MOD) % MOD;
        };

        for (int j = 0; j < m; j++) {
            dp.at(i).at(j) = (sum(0, j-k) + sum(j+k, m-1)) % MOD;
        }
    }

    ll ans = 0;
    for (int i = 0; i < m; i++) {
        ans += dp.at(n).at(i);
        ans %= MOD;
    }
    cout << ans << endl;

    return 0;
}