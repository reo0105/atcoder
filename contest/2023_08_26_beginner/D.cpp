#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
#define INF 1e18

int main() {
    
    int n;
    cin >> n;

    vector<int> x(n), y(n), z(n);
    ll now = 0;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i] >> z[i];
        if (x[i] > y[i]) now += z[i];
        sum += z[i];
    }

    vector<ll> dp(100005, INF);
    for (int i = 0; i <= now; i++) dp[i] = 0;

    for (int j = 0; j < n; j++) {
        for (int i = 100004; i >= 0; i--) {
            if (x[j] > y[j]) continue;

            int rem = (y[j] - x[j] + 1) / 2;

            if (i+z[j] < 100004) dp[i+z[j]] = min(dp[i+z[j]], dp[i]+rem);
        }
    }

    ll ans = INF;
    for (int i = (sum+1)/2; i <= sum; i++) {
        // cout << i << " " << dp[i] << endl;
        ans = min(ans, dp[i]);
    }

    cout << ans << endl;


    return 0;
}