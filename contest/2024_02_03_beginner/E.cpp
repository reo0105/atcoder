#include <bits/stdc++.h>
using namespace std;
#include <atcoder/segtree>
using namespace atcoder;

int op(int a, int b) { return max(a, b); }
int e() { return 0; }

int main()
{
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int m = 500005;    
    segtree<int, op, e> dp(m);

    for (int i = 0; i < n; i++) {
        int l = a[i]-d, r = a[i]+d+1;
        l = max(l, 0);
        r = min(r, m);
        int now = dp.prod(l, r) + 1;

        dp.set(a[i], now);
    }


    int ans = dp.prod(0, m);
    cout << ans << endl;
    return 0;
}