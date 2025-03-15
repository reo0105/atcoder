#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> dp(n+5, 0);
    dp[1] = a[0];

    for (int i = 1; i < n; i++) {
        dp[i+1] = dp[i] + a[i];
        dp[i+1] = max(dp[i+1], dp[i-1]);
        if (i >= 2) {
            dp[i+1] = max(dp[i+1], dp[i-2] + a[i]);
        }
    }

    // for (int i = 1; i <= n; i++) cout << dp[i] << " ";
    // cout << endl;

    cout << dp[n] << endl;

    return 0;

}
