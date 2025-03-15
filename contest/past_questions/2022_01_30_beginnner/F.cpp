#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<vector<vector<ll>>>> dp(1005, vector<vector<vector<ll>>>(12, vector<vector<ll>>(12, vector<ll>(12, 0))));

    dp.at(0).at(m+1).at(m+1).at(m+1) = 1;
    for (int i = 1; i <= n; i++) {
        for (int a1 = 1; a1 <= m+1; a1++) {
            for (int a2 = 1; a2 <= m+1; a2++) {
                for (int a3 = 1; a3 <= m+1; a3++) {
                    for (int x = 1; x <= m; x++) {
                        if (x <= a1) {
                            dp.at(i).at(x).at(a2).at(a3) += dp.at(i-1).at(a1).at(a2).at(a3);
                            dp.at(i).at(x).at(a2).at(a3) %= MOD;
                        } else if (x <= a2) {
                            dp.at(i).at(a1).at(x).at(a3) += dp.at(i-1).at(a1).at(a2).at(a3);
                            dp.at(i).at(a1).at(x).at(a3) %= MOD;
                        } else if (x <= a3) {
                            dp.at(i).at(a1).at(a2).at(x) += dp.at(i-1).at(a1).at(a2).at(a3);
                            dp.at(i).at(a1).at(a2).at(x) %= MOD;
                        }
                    }
                }
            }
        }
    }

    ll ans = 0;
    for (int a1 = 1; a1 <= m; a1++) {
        for (int a2 = a1+1; a2 <= m; a2++) {
            for (int a3 = a2+1; a3 <= m; a3++) {
                ans += dp.at(n).at(a1).at(a2).at(a3);
                ans %= MOD;
            }
        }
    }

    cout << ans << endl;

    return 0;
}