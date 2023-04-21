#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
#define MOD 998244353

ll modinv(ll a)
{
    ll ret = 1;
    ll y = MOD-2;
    while (y > 0) {
        if (y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

int main()
{
    int n, a, b, p, q;
    cin >> n >> a >> b >> p >> q;

    vector<vector<vector<ll>>> dp(105, vector<vector<ll>>(105, vector<ll>(2, 0)));
    // vector<vector<ll>> dp(105, vector<ll>(105, 0));

    dp.at(a).at(b).at(0) = 1;

    ll pinv = modinv(p);
    ll qinv = modinv(q);

    for (int i = a; i < n; i++) {
        for (int j = b; j < n; j++) {

            for (int ta = 1; ta <= p; ta++) {
                dp.at(min(i+ta, n)).at(j).at(1) += dp.at(i).at(j).at(0) * pinv;
                dp.at(min(i+ta, n)).at(j).at(1) %= MOD;
            }

            for (int ao = 1; ao <= q; ao++) {
                dp.at(i).at(min(j+ao, n)).at(0) += dp.at(i).at(j).at(1) * qinv;
                dp.at(i).at(min(j+ao, n)).at(0) %= MOD;
            }
        }
    }

    ll ans = 0;
    for (int i = b; i < n; i++) {
        ans += dp.at(n).at(i).at(1);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}
