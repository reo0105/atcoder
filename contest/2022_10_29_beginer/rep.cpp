#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

ll modpow(ll a, ll y)
{
    ll ret = 1;
    while(y > 0) {
        if (y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

ll modinv(ll a)
{
    return modpow(a, MOD-2);
}

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<ll>> dp(1005, vector<ll>(1005, 0));

    ll invm = modinv(m);
    dp.at(0).at(0) = 1;

    for (int i = 0; i < k; i++) {
        dp.at(i+1).at(n) += dp.at(i).at(n);
        for (int j = 0; j < n; j++) {
            for (int l = 1; l <= m; l++) {
                if (j+l <= n) {
                    dp.at(i+1).at(j+l) += dp.at(i).at(j) * invm;
                    dp.at(i+1).at(j+l) %= MOD;
                } else {
                    dp.at(i+1).at(2*n-j-l) += dp.at(i).at(j) * invm;
                    dp.at(i+1).at(2*n-j-l) %= MOD;
                }
            }
        }
    }

    cout << dp.at(k).at(n) << endl;

}