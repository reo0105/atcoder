#include <bits/stdc++.h>
using namespace std;

void dfs(int& ans, int next, int n, int t, vector<vector<int>> team, vector<vector<bool>> bad)
{
    if (next == n) {
        if ((int)team.size() == t) ans++;
        return;
    }

    for (int i = 0; i < (int)team.size(); i++) {
        int ok = 1;
        for (int p : team[i]) {
            if (bad[p][next]) ok = 0;
        }

        if (!ok) continue;
        team[i].push_back(next);
        dfs(ans, next+1, n, t, team, bad);
        team[i].pop_back();
    }

    team.push_back(vector<int>(1, next));
    dfs(ans, next+1, n, t, team, bad);
    team.pop_back();
}

int main()
{
    int n, t, m;
    cin >> n >> t >> m;

    vector<vector<bool>> bad(n, vector<bool>(n, false));

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--; b--;
        bad[a][b] = true;
        bad[b][a] = true;
    }

    int ans = 0;
    
    vector<vector<int>> team;

    dfs(ans, 0, n, t, team, bad);

    cout << ans << endl;

    return 0;
}