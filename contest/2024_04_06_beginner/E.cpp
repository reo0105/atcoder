#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> to(n);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;

        to[a].push_back(b);
        to[b].push_back(a);
    }

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    ll tot = 0;
    for (int i = 0; i < n; i++) tot += c[i];

    int x = -1;
    {
        auto dfs = [&](auto dfs, int v, int p=-1) -> ll {
            ll res = c[v];
            ll maxi = 0;
            for (int u : to[v]) {
                if (u != p) {
                    ll now = dfs(dfs, u, v);
                    maxi = max(maxi, now);
                    res += now;
                }
            }
            maxi = max(maxi, tot-res);
            if (maxi*2 <= tot) x = v;
            return res;
        };
        dfs(dfs, 0);
    }

    ll ans = 0;
    auto dfs = [&](auto dfs, int v, int dist = 0, int p=-1) -> void {
        ans += (ll)dist*c[v];
        for (int u : to[v]) {
            if (u != p) {
                dfs(dfs, u, dist+1, v);
            }
        }
    };
    dfs(dfs, x);
    cout << ans << endl;

    return 0;
}