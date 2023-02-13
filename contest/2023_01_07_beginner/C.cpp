#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(105);
vector<bool> seen(105, false);

void dfs(int from)
{
    seen.at(from) = true;

    for (auto next : G.at(from)) {
        if (seen.at(next)) continue;
        dfs(next);
    }

    return;
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

    for (int i = 1; i <= n; i++) {
        if (!seen.at(i)) {
            dfs(i);
            cnt++;
        }
    }

    cout << cnt << endl;


    return 0;
}