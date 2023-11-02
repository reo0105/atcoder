#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, pair<int, int>> pii;

void dfs(int from, vector<pair<ll, ll>> &ans, vector<vector<pii>> &G)
{
    for (pii pi : G[from]) {
        int to = pi.first;
        int x = pi.second.first;
        int y = pi.second.second;

        if (ans[to] == make_pair(-1LL, -1LL)) {
            ans[to] = make_pair(ans[from].first + x, ans[from].second + y);
            dfs(to, ans, G);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> G(200005);

    for (int i = 0; i < m; i++) {
        int a, b, x, y;
        cin >> a >> b >> x >> y;
        G[a].push_back(make_pair(b, make_pair(x, y)));
        G[b].push_back(make_pair(a, make_pair(-x, -y)));
    }

    vector<pair<ll, ll>> ans(200005, make_pair(-1L, -1L));

    ans[1] = make_pair(0L, 0L);
    dfs(1, ans, G);

    for (int i = 1; i <= n; i++) {
        if (ans[i] == make_pair(-1LL, -1LL)) {
            cout << "undecidable" << endl;
        } else {
            cout << ans[i].first << " " << ans[i].second << endl;
        }
    }

    return 0;
}