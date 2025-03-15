#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
#define MOD 998244353

int main()
{
    int n, m;
    int a, b, c, d, e, f;
    set<p> obj;

    cin >> n >> m;
    cin >> a >> b >> c >> d >> e >> f;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        obj.insert(make_pair(x, y));
    }

    vector<vector<vector<ll>>> dp(305, vector<vector<ll>>(305, vector<ll>(305, 0)));

    dp.at(0).at(0).at(0) = 1;
    for (int i = 0; i < n; i++) { //i回のワープのうち
        for (int xi = 0; xi < n; xi++) { //ワープ1をxi回
            for (int yi = 0; yi < n; yi++) { //ワープ2をyi下位 -->> ワープ3はn-xi-yi回になる
                if (xi+yi > i) break;

                int x1 = a*(xi+1) + c*yi + e*(i-xi-yi);
                int y1 = b*(xi+1) + d*yi + f*(i-xi-yi);
                if (!obj.count(make_pair(x1, y1))) {
                    dp.at(i+1).at(xi+1).at(yi) += dp.at(i).at(xi).at(yi);// + dp.at(i-1).at(xi).at(yi-1) + dp.at(i-1).at(xi).at(yi);
                    dp.at(i+1).at(xi+1).at(yi) %= MOD;
                }

                int x2 = a*xi + c*(yi+1) + e*(i-xi-yi);
                int y2 = b*xi + d*(yi+1) + f*(i-xi-yi);
                if (!obj.count(make_pair(x2, y2))) {
                    dp.at(i+1).at(xi).at(yi+1) += dp.at(i).at(xi).at(yi);// + dp.at(i-1).at(xi).at(yi-1) + dp.at(i-1).at(xi).at(yi);
                    dp.at(i+1).at(xi).at(yi+1) %= MOD;
                }

                int x3 = a*xi + c*yi + e*(i-xi-yi+1);
                int y3 = b*xi + d*yi + f*(i-xi-yi+1);
                if (!obj.count(make_pair(x3, y3))) {
                    dp.at(i+1).at(xi).at(yi) += dp.at(i).at(xi).at(yi);// + dp.at(i-1).at(xi).at(yi-1) + dp.at(i-1).at(xi).at(yi);
                    dp.at(i+1).at(xi).at(yi) %= MOD;
                }
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i+j > n) continue;
            ans += dp.at(n).at(i).at(j);
            ans %= MOD;
        }
    }
    
    cout << ans << endl;

    return 0;
}