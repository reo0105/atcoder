#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    int n;
    vector<ll> a(105);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    ll ans = 0;
    for (int i = 1; i <= n; i++) { //i
        vector<vector<vector<ll>>> dp(105, vector<vector<ll>>(105, vector<ll>(105, 0)));
        dp.at(0).at(0).at(0) = 1;
        for (int j = 1; j <= n; j++) { //先頭j
            for (int k = 0; k <= i; k++) { //k個選ぶ
                for (int l = 0; l < i; l++) { //あまり
                    dp.at(j).at(k).at(l) += dp.at(j-1).at(k).at(l);
                    dp.at(j).at(k).at(l) %= MOD;
                    if (k != i) {
                        dp.at(j).at(k+1).at((l+a.at(j))%i) += dp.at(j-1).at(k).at(l);
                        dp.at(j).at(k+1).at((l+a.at(j))%i) %= MOD;
                    }
                }
            }
        }
        ans += dp.at(n).at(i).at(0);
        ans %= MOD;
    }

    cout << ans << endl;

    return 0;
}