#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

vector<p> ans1;
vector<p> ans2;
vector<vector<int>> G(200005);
vector<bool> seen(200005, false);

void dfs(int from)
{
    seen.at(from) = true;

    for (int v : G.at(from)) {
        if (seen.at(v)) continue;
        ans1.push_back(make_pair(from, v));
        dfs(v);
    }

    return;
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> u(200005), v(200005);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    dfs(1);

    queue<int> que;
    vector<int> dist(200005, -1);

    que.push(1);
    dist.at(1) = 0;

    while (que.size()) {
        int u = que.front();
        que.pop();

        for (int v : G.at(u)) {
            if (dist.at(v) != -1) continue;

            dist.at(v) = dist.at(u) + 1;
            ans2.push_back(make_pair(u, v));
            que.push(v);
        }
    }

    for (p x : ans1) cout << x.first << " " << x.second << endl;
    for (p x : ans2) cout << x.first << " " << x.second << endl;

    return 0;
}