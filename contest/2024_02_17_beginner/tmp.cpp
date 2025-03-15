#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;


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

    vector<int> w(n);
    vector<pii> wi(n);
    for (int i = 0; i < n; i++) {
        cin >> w[i];
        wi[i] = make_pair(w[i], i);
    }

    sort(wi.begin(), wi.end());

    vector<int> dp(n, -1);

    for (pii tmp : wi) {
        int wei = tmp.first;
        int v = tmp.second;

        vector<int> dp2(w[v]+5, 0);
        for (int u : G[v]) {
            if (w[u] >= w[v]) continue;

            for (int j = w[v]; j > w[u]; j--) {
                dp2[j] = max(dp2[j], dp2[j-w[u]] + dp[u]);
            }
        }

        dp[v] = dp2[w[v]] + 1;
    }

    ll ans = 0;
    ll a;
    for (int i = 0; i < n; i++) {
        cin >> a;
        ans += a * dp[i];
    }

    cout << ans << endl;
    
    return 0;
}