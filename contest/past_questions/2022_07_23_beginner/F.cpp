#include <bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;
typedef long long ll;

ll op(ll a, ll b) { return a+b; }
ll e() { return 0LL; }

int main()
{
    int n;
    vector<int> c(300005), x(300005);

    cin >> n;
    segtree<ll, op, e> seg(n+1);
    vector<vector<int>> color(300005);
    for (int i = 1; i <= n; i++) cin >> c.at(i);
    for (int i = 1; i <= n; i++) cin >> x.at(i);
    for (int i = 1; i <= n; i++) {
        color.at(c.at(i)).push_back(x.at(i));
        color.at(0).push_back(x.at(i));
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++) {
        int d = (int)color.at(i).size();
        for (int j = 0; j < d; j++) {
            if (i == 0) ans += seg.prod(color.at(i).at(j)+1, n+1);
            else ans -= seg.prod(color.at(i).at(j)+1, n+1);
            ll now = seg.get(color.at(i).at(j));
            seg.set(color.at(i).at(j), now + 1);
            // cout << j << " " << ans << endl;
        }
        for (int j = 0; j < d; j++) seg.set(color.at(i).at(j), 0);
    }

    cout << ans << endl;

    return 0;
}