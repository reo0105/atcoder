#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    int ans = 0;
    vector<vector<int>> G(2005);
    vector<set<int>> s(2005);
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        s.at(u).insert(v);
        // G.at(v).push_back(u);
    }


    for (int i = 1; i <= n; i++) {
        vector<int> dist(2005, 0);
        queue<int> que;

        dist.at(i) = 1;
        que.push(i);

        while(que.size()) {
            int u = que.front();
            que.pop();

            for (int v : G.at(u)) {
                if (dist.at(v) != 0) continue;
                dist.at(v) = dist.at(u)+1;
                que.push(v);
                if (dist.at(u) != 1) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}