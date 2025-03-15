#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

// vector<ll> f(2605);
// vector<ll> finv(2605);

// ll modpow(ll x)
// {
//     ll ret = 1;
//     ll y = MOD - 2;

//     while (y > 0) {
//         if (y & 1) ret = ret * x % MOD;
//         x = x * x % MOD;
//         y >>= 1;
//     }

//     return ret;
// }

// void init()
// {
//     f.at(1) = 1; finv.at(1) = 1;

//     for (int i = 2; i <= 2600; i++) {
//         f.at(i) = f.at(i-1) * i % MOD;
//         finv.at(i) = finv.at(i-1) * modpow(i) % MOD;
//     }
// }

// int main()
// {
//     ll n, m, k;
//     cin >> n >> m >> k;
//     init();
//     k -= n;

//     ll ans = 1;

//     for (int i = 1; i <= k; i++) {
//         ll t = f.at(i+n-1) * finv.at(i);
//         t %= MOD;
//         t *= finv.at(n-1);
//         t %= MOD;
//         ans += t; //f.at(i+n-1) * finv.at(i) * finv.at(n-1);
//         // cout << f.at(i+n-1) << " " << finv.at(i)  << " " << finv.at(n-1) << " ";
//         // cout << i << " : " << ans << endl;
//         ans %= MOD;
//     }

//     cout << ans << endl;

//     return 0;
// }

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> dp(55, vector<int>(3000, 0));

    
    for (int i = 1; i <= m; i++) dp.at(1).at(i) = 1;

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            for (int l = 1; l <= m; l++) {
                if (j-l >= 1) dp.at(i).at(j) += dp.at(i-1).at(j-l);
                dp.at(i).at(j) %= MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = 1; i <= k; i++) {
        ans += dp.at(n).at(i);
        ans %= MOD;
    }
    cout << ans << endl; 

    return 0;
}