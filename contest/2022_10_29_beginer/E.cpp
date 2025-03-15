#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
#define MOD 998244353
ll gcd(ll a, ll b)
{
    if (a % b == 0) {
        return b;
    } else {
        return gcd(b, a%b);
    }
}
ll modpow(ll a, ll n, ll mod) // a^n modを求める
{
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
ll modinv(ll a, ll mod) // a^(-1) modを求める
{
    return modpow(a, mod-2, mod);
}
int main()
{
    ll n, m, k, gnum;
    ll cnt_all = 0, cnt_n = 0;
    vector<vector<ll>> dp(1002, vector<ll>(1012, 0));
    cin >> n >> m >> k;

    for (int i = 1; i <= m; i++) {
        dp.at(1).at(i) = 1;
    }

    for (int i = 1; i < k; i++) {
        for (int j = 0; j < n; j++) {
            for (int t = 1; t <= m; t++) {
                if (dp.at(i).at(j) > 0) {
                    dp.at(i+1).at(j+t) += dp.at(i).at(j);
                    dp.at(i+1).at(j+t) %= MOD;
                    for (int l = 1; l<=t; l++) {
                        if (dp.at(i+1).at(n+l) != 0) {
                            dp.at(i+1).at(n-l) += dp.at(i+1).at(n+l);
                            dp.at(i+1).at(n-l) %= MOD;
                            dp.at(i+1).at(n+l) = 0;
                        }
                    }
                }
            }
        }
        dp.at(i+1).at(n) += dp.at(i).at(n) * m;
        dp.at(i+1).at(n) %= MOD;
    }

    for (int j = 0; j <= n; j++) {
        cnt_all += dp.at(k).at(j);
        cnt_all %= MOD;
    }

    cnt_n = dp.at(k).at(n);

    if (cnt_n == 0) {
        cout << 0 << endl;
    } else {
        if ((gnum = gcd(cnt_all, cnt_n)) != 1) {
            cnt_all /= gnum;
            cnt_n /= gnum;
        }
        cout << ((modinv(cnt_all, MOD) * cnt_n) + MOD) % MOD << endl; //xの逆元もとめて1になるのはフェルマーの小定理から分かるけどyになるのがわからん
    }


    return 0;
}