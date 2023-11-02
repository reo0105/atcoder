#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> G(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i-1; j++) {
            int d;
            cin >> d;
            G[i].push_back(d);
        }
    }
    

    // vector<vector<ll> dp(20, vector<ll>(100000, 0));
    vector<ll> dp(100000, 0);

    for (int s = 0; s < (1<<n); s++) {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (i == j) continue;
                if (s == 0 || ((s & (1<<i)) == 0) && ((s & (1<<j)) == 0)) {
                    // int ti = i, tj = j;
                    // if (i > j) swap(ti, tj);
                    dp[s | (1<<i) | (1<<j)] = max(dp[s | (1<<i) | (1 << j)], dp[s] + G[i][j-i-1]);
                }
            }
        }
    }

    ll ans = dp[(1<<n)-1];
    for (int i = 0; i < n; i++) {
        ans = max(ans, dp[((1<<n)-1) ^ (1<<i)]);
    }

    cout << ans << endl;

    return 0;
}