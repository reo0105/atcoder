#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(200005);
vector<bool> seen(200005, false);

int dfs(int from, int cnt)
{
    seen.at(from) = true;
    cnt++;

    if (cnt >= 1000000) return 1000000;

    for (auto next : G.at(from)) {
        if (seen.at(next)) continue;
        cnt = dfs(next, cnt);
    }

    seen.at(from) = false;

    return cnt;
}

int main()
{
    int n, m, cnt = 0;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    cnt = dfs(1, cnt);

    cout << cnt << endl;


    return 0;
}