#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    
    vector<int> d(n);
    for (int i = 0; i < n; i++) cin >> d[i];

    int l1, k1; ll c1;
    int l2, k2; ll c2;

    cin >> l1 >> c1 >> k1;
    cin >> l2 >> c2 >> k2;

    const ll INF = 1e18;
    vector<ll> dp(k1+1, INF);

    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        vector<ll> p(k1+1, INF);
        swap(dp, p);
        for (int x1 = 0; x1 < k1+1; x1++) {
            int x2 = ((d[i]-l1*x1)+l2-1)/l2;
            x2 = max(x2, 0);
            for (int j = 0; j < k1+1-x1; j++) {
                dp[j+x1] = min(dp[j+x1], p[j]+x2);
            }
        }
    }

    ll ans = 1e18;
    for (int i = 0; i < k1+1; i++) {
        int j = dp[i];
        if (j > k2) continue;
        ll now = i*c1 + j*c2;
        ans = min(ans, now);
    }

    if (ans == 1e18) ans = -1;
    cout << ans << endl;

    return 0;    
}