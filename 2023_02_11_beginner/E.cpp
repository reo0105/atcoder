#include <bits/stdc++.h>
using namespace std;
#define INF 1<<29
typedef pair<int, bool> pb;
typedef pair<int, int> pi;

// vector<pi> dist(2005);
// void dfs(int from)
// {
//     dist_d.at(from).first = 0;

//     for (int next : G.at(from)) {
//         if (dist_d.at(next) != -1) continue;
//         t++;
//         dfs(next);
//     }

//     t++;
//     dist_f.at(from) = t;

// }

int main()
{
    int t;
    int n, m, u, v;
    vector<int> c(2005);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        for (int j = 1; j <= n; j++) cin >> c.at(j);

        vector<vector<pb>> G(2005);
        for (int j = 0; j < m; j++) {
            cin >> u >> v;
            G.at(u).push_back(make_pair(v, true));
            G.at(v).push_back(make_pair(u, true));
        }

        // int ans = -1;
        // ans = dfs(1);

        int cnt = (c.at(1) == 0) ? -1 : 1;
        vector<vector<pi>> dist(2005);
        queue<tuple<int, int, int>> que;
        dist.at(1).push_back(make_pair(0, cnt));
        que.push(make_tuple(1, 0, cnt));
        int ans = -1;
        cnt = 0;
        // int fu = -1, fv = -1;
        while(!que.empty()) {
            tuple tup = que.front();
            que.pop();
            int tu = get<0>(tup);
            int dist = get<1>(tup);
            int cost = get<2>(tup);

            for (auto &tn : G.at(tu)) {
                int tv = tn.first;
                int ok = tn.second;
                // cout << fu << " " << tu << " " << fv << " " << tv << endl;
                if (cnt > m*1000) goto end;
                
                cnt++;
                // tn.second = false;
                // tn.second = false;
                // cout << tu << " " << tv << " " << dist+1 << " " << cost << endl;
                
                if (c.at(tv) == 0) que.push(make_tuple(tv, dist+1, cost-1));
                else que.push(make_tuple(tv, dist+1, cost+1));

                if (tv == n && ((cost == 1 && c.at(tv) == 0) || (cost == -1 && c.at(tv) == 1))) { ans = dist + 1; goto end; }
            }
        }
end:
        cout << ans << endl;
    }

    return 0;
}