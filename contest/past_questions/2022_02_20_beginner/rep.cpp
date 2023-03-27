#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;


int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        vector<p> c;
        for (int i = 0; i < n; i++) {
            ll x, y;
            cin >> x >> y;
            c.push_back(make_pair(x, y));
        }

        ll ans = -1e18, a = 0, b = 0;
        for (p tmp : c) {
            ll cx = tmp.first;
            ll cy = tmp.second;
            ans = max(ans, a + b + cx);

            if (b > 0 && cx < 0) {
                ll cnt = b / (-1*cx);
                ll ta = -1e18;
                if (cnt < cy) ta = a + b * cnt +  cx * cnt * (cnt + 1) / 2;
                // b = b + cx * cnt;
                ans = max(ans, ta);
            }

            // cout << a << " " << b << " " << ans << endl;
            a = a + b * cy +  cx * cy * (cy + 1) / 2;
            b = b + cx * cy;
            ans = max(ans, a);
            // cout << a << " " << b << " " << ans << endl;
        }

        cout << ans << endl;
    }

    return 0;
}