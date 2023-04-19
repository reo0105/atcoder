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

    vector<vector<ll>> dp(105, vector<ll>(105, 0));

    dp.at(a).at(b) = 1;

    for (int l = 0; l < n-a; l++) {

        if (b+l < n) {
            for (int i = 1; i < n; i++) {
                dp.at(i).at(n) *= p;
                dp.at(i).at(n) %= MOD; 
            }
        }
        for (int ao = b+l; ao < n; ao++) {
            // dp.at(n).at(ao) %= MOD;
            for (int ta = n-1; ta >= 1; ta--) {
                for (int si = 1; si <= p; si++) {
                    // if (ta+si <= n) {
                        dp.at(min(ta+si, n)).at(ao) += dp.at(ta).at(ao);
                        dp.at(min(ta+si, n)).at(ao) %= MOD;
                    // }
                }
            }
        }

        if (l == n-a-1) break;

        if (a+l+1 < n) {
            for (int i = 1; i < n; i++) {
                dp.at(n).at(i) *= q;
                dp.at(n).at(i) %= MOD;
            }
        }
        for (int ta = a+l+1; ta < n; ta++) {
            // dp.at(ta).at(n) %= MOD;
            for (int ao = n-1; ao >= 1; ao--) {
                for (int si = 1; si <= q; si++) {
                    // if (ao+si <= n) {
                        dp.at(ta).at(min(ao+si, n)) += dp.at(ta).at(ao);
                        dp.at(ta).at(min(ao+si, n)) %= MOD;
                    // }
                }
            }
        }
    }

    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         cout << dp.at(i).at(j) << " ";
    //     }
    //     cout << endl;
    // }

    ll y = 0, x = 0;
    for (int i = 1; i < n; i++) {
        x += dp.at(n).at(i);
        x += dp.at(i).at(n);
        x %= MOD;
    }

    for (int ao = 1; ao < n; ao++) {
        y += dp.at(n).at(ao);
        y %= MOD;
    }
    cout << x << " " << y << endl;

    ll re = modinv(x);

    cout << re*y % MOD << endl;


    return 0;
}