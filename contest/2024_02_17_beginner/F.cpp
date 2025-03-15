#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main()
{  
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n);
    
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    vector<int> w(n), a(n);
    vector<pii> wi(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        wi[i] = make_pair(w[i], i);
    }
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(wi.begin(), wi.end());

    vector<int> dp(n);
    for (pii tmp : wi) {
        int v = tmp.second;
        vector<int> dp2(w[v]);
        for (int u : G[v]) {
            if (w[u] >= w[v]) continue;

            for (int j = w[v]-1; j >= w[u]; j--) {
                dp2[j] = max(dp2[j], dp2[j-w[u]] + dp[u]);
            }
        }
        if (w[v] == 0) dp[v] = 1;
        else dp[v] = dp2[w[v]-1] + 1;
    }

    ll ans =0;
    for (int i = 0; i < n; i++) ans += ll(a[i]) * dp[i];
    
    cout << ans << endl;

    

    return 0;
}