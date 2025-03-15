#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppi;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> to(n);
    for (int i = 0; i < n; i++) {
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

    int x;
    {
        auto dfs = [&](auto dfs, int u, int p=-1) -> ll {
            ll ret = c[u];
            ll maxi = 0;
            for (int v : to[u]) {
                ll now = dfs(dfs, v, u);
                maxi = max(maxi, now);
                ret += now;
            }
            maxi = max(maxi, tot-ret);
            if (maxi*2 <= tot) x = u;
            return ret;
        };
        dfs(dfs, 0);
    }

    auto dfs = [&](auto dfs, int u, int p=-1) -> ll {
        ll ans = ;

    }


    cout << dfs(dfs, x) << endl;

    return 0;
}
