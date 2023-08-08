#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

bool dfs(int from, vector<int> &seen, vector<vector<int>> &G, int c, ll &cnt0, ll &cnt1)
{
    seen[from] = c;
    int nc = c^1;

    if (nc) cnt1++;
    else cnt0++;

    for (int u : G[from]) {
        if (seen[u] == -1) {
            if (!dfs(u, seen, G, nc, cnt0, cnt1)) return false;
        } else if (seen[u] == c) {
            return false;
        }
    }

    return true;
}


int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(n);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    vector<int> seen(n, -1);

    ll ans = (ll)n * (n-1) / 2 - m;
    
    for (int i = 0; i < n; i++) {
        if (seen[i] == -1) {
            ll cnt0 = 0, cnt1 = 0;
            if (!dfs(i, seen, G, 0, cnt0, cnt1)) {
                cout << 0 << endl;
                return 0;
            }

            ans -= cnt0 * (cnt0 - 1) / 2;
            ans -= cnt1 * (cnt1 - 1) / 2;
        }
    }

    cout << ans << endl;    
 
    return 0;
}