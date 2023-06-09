#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define MOD 998244353

int main()
{
    int n, m;
    int a, b, c, d, e, f;

    cin >> n >> m;
    cin >> a >> b >> c >> d >> e >> f;

    set<p> obj;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        obj.insert(make_pair(x, y));
    }

    vector<vector<vector<ll>>> dp(305, vector<vector<ll>>(305, vector<ll>(305, 0)));

    dp.at(0).at(0).at(0) = 1;

    for (int i = 1; i <= n; i++) {
        for (int ai = 0; ai <= i; ai++) {
            for (int bi = 0; bi <= i-ai; bi++) {
                int ci = i-ai-bi;

                ll x, y;
                x = (ll)a * ai + c * bi + e * ci;
                y = (ll)b * ai + d * bi + f * ci;
                if (!obj.count(make_pair(x, y))) {
                    if (ai != 0) dp.at(i).at(ai).at(bi) += dp.at(i-1).at(ai-1).at(bi);
                    if (bi != 0) dp.at(i).at(ai).at(bi) += dp.at(i-1).at(ai).at(bi-1);
                    dp.at(i).at(ai).at(bi) += dp.at(i-1).at(ai).at(bi);
                    dp.at(i).at(ai).at(bi) %= MOD; 
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n-i; j++) {
            ans += dp.at(n).at(i).at(j);
            ans %= MOD;
        }
    }

    cout << ans << endl;


    return 0;
}