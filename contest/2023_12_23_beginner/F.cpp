#include<bits/stdc++.h>
using namespace std;
#include <atcoder/segtree>
using namespace atcoder;

typedef long long ll;

double op(double x, double y) { return min(x, y); }
double e() { return 1e18; }

int main()
{
    int n, k;
    cin >> n >> k;

    ll sx, sy;
    cin >> sx >> sy;

    vector<ll> x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];

    vector<double> d(n+1, 0);
    double ans = 0;
    for (int i = 0; i < n-1; i++) {
        double dir = sqrt((x[i+1] - x[i]) * (x[i+1] - x[i]) + (y[i+1] - y[i]) * (y[i+1] - y[i]));
        double indir0 = sqrt((sx - x[i]) * (sx - x[i]) + (sy - y[i]) * (sy - y[i]));
        double indir1 = sqrt((x[i+1] - sx) * (x[i+1] - sx) + (y[i+1] - sy) * (y[i+1] - sy));
        d[i+1] = (indir0 + indir1) - dir;
        ans += dir;
    }

    ans += sqrt((sx - x[0]) * (sx - x[0]) + (sy - y[0]) * (sy - y[0]));
    ans += sqrt((sx - x[n-1]) * (sx - x[n-1]) + (sy - y[n-1]) * (sy - y[n-1]));

    vector<double> dp(n);
    segtree<double, op, e> seg(n+1);
    
    seg.set(0, 0);
    for (int i = 1; i <= n; i++) {
        int l = max(i-k, 0);
        double mini = seg.prod(l, i+1);
        seg.set(i, mini + d[i]);
    }

    cout << setprecision(15) << ans + seg.get(n) << endl;

}