#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

ll modinv(ll a)
{
    ll ret = 1;
    ll y = MOD - 2;

    while (y > 0) {
        if (y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

int main()
{  
    ll n;  
    cin >> n;

    int two = 0, three = 0, five = 0;

    while (n % 2 == 0) {
        two++;
        n /= 2;
    }

    while (n % 3 == 0) {
        three++;
        n /= 3;
    }

    while (n % 5 == 0) {
        five++;
        n /= 5;
    }

    vector<vector<vector<ll>>> dp(100, vector<vector<ll>>(100, vector<ll>(100, 0)));
    ll invf = modinv(5);

    dp.at(0).at(0).at(0) = 1;

    for (int i = 0; i <= two; i++) {
        for (int j = 0; j <= three; j++) {
            for (int k = 0; k <= five; k++) {
                dp.at(i+1).at(j).at(k) += dp.at(i).at(j).at(k) * invf;
                dp.at(i).at(j+1).at(k) += dp.at(i).at(j).at(k) * invf;
                dp.at(i+2).at(j).at(k) += dp.at(i).at(j).at(k) * invf;
                dp.at(i).at(j).at(k+1) += dp.at(i).at(j).at(k) * invf;
                dp.at(i+1).at(j+1).at(k) += dp.at(i).at(j).at(k) * invf;
                dp.at(i+1).at(j).at(k) %= MOD;
                dp.at(i).at(j+1).at(k) %= MOD;
                dp.at(i+2).at(j).at(k) %= MOD;
                dp.at(i).at(j).at(k+1) %= MOD;
                dp.at(i+1).at(j+1).at(k) %= MOD;
            }
        }
    }

    if (n != 1) cout << 0 << endl;
    else cout << dp.at(two).at(three).at(five) << endl;

    return 0;
}