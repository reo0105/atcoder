#include<bits/stdc++.h>
#include <atcoder/segtree>
using namespace std;
using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, pii> ppi;

int op(int x, int y) { return max(x, y); }
int e() {return 0; }

int main()
{
    int n, d;
    cin >> n >> d;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    segtree<int, op, e> dp(500005);

    for (int i = 0; i < n; i++) {
        int now = a[i];
        int l = max(0, a[i] - d);
        int r = min(500003, a[i] + d + 1);

        int maxi = dp.prod(l, r);
        dp.set(now, maxi + 1);
    }

    // int ans = 0;
    // for (int i = 0; i < 500003; i++) ans = max(ans, dp.get(i));

    cout << dp.prod(0, 500003) << endl;


    return 0;
}