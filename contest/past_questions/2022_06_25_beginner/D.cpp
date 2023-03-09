#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1L<<58

int main()
{
    int n;
    vector<ll> x(205), y(205), p(205);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> x.at(i) >> y.at(i) >> p.at(i);

    // ll l = 0, r = 4e9;
    // while (r - l > 1) { 
        // ll mid = (l + r) / 2;
        vector<vector<ll>> d(205, vector<ll>(205, 0));

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                ll dist = abs(x.at(i) - x.at(j)) + abs(y.at(i) - y.at(j));
                d.at(i).at(j) = (dist-1) / p.at(i) + 1;
            }
        }

        for (int k = 1; k <= n; k++) {
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    d.at(i).at(j) = min(d.at(i).at(j), max(d.at(i).at(k), d.at(k).at(j)));
                }
            }
        }

        ll ans = INF;
        for (int i = 1; i <= n; i++) {
            ll t = 0;
            for (int j = 1; j <= n; j++) {
                t = max(t, d.at(i).at(j));
            }
            ans = min(ans, t);
        }

        // if (ok) r = mid;
        // else l = mid;
    // }

    cout << ans << endl;

    return 0;
}