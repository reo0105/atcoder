#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

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

    ll ans = (ll)n*(n-1)*(n-2) / 6;
    ans += n*(ll)(n-1)/2;

    auto dfs = [&](auto dfs, int v, int p=-1) -> int {
        int t = 1;
        for (int u : to[v]) {
            if (u != p) {
                int r = dfs(dfs, u, v);
                ans -= r*ll(n-r);
                t += r;
            }
        }
        return t;
    };

    dfs(dfs, 0);
    cout << ans << endl;

    return 0;
}