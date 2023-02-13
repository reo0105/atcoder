#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

vector<vector<int>> G(200005);
vector<vector<int>> ans(2, vector<int>(200005));

int dfs(int from, int par, int cnt = 1)
{
    ans.at(0).at(from) = cnt;

    for (int next : G.at(from)) {
        if (next == par) continue;
        // cout << from << " " << next << " " << par << " " << cnt << endl;
        cnt = dfs(next, from, cnt);
    }

    ans.at(1).at(from) = cnt;
    if (ans.at(0).at(from) == ans.at(1).at(from)) cnt++;
    else ans.at(1).at(from)--;

    return cnt;
}


int main()
{
    int n;

    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    dfs(1, -1);

    for (int i = 1; i <= n; i++) {
        cout << ans.at(0).at(i) << " " << ans.at(1).at(i) << endl;
    }

    return 0;
}