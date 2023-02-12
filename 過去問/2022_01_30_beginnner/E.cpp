#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define INF 1<<29

vector<vector<int>> G(200005);
vector<int> dist(200005, INF);

void dijkstra(vector<int> h)
{
    priority_queue<p, vector<p>, greater<p>> que;
    dist.at(1) = 0;
    que.push(make_pair(0, 1));

    while (!que.empty()) {
        int d = que.top().first;
        int u = que.top().second;
        que.pop();
        if (dist.at(u) < d) continue;
        for (int v : G.at(u)) {
            int cost = max(0, h.at(v) - h.at(u));
            if (dist.at(v) > d+cost) {
                dist.at(v) = d + cost;
                que.push(make_pair(dist.at(v), v));
            }
        }
    }

    return;
}


int main()
{
    int n, m;
    vector<int> h(200005);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> h.at(i);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    dijkstra(h);

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        int cost = h.at(1) - h.at(i) - dist.at(i);
        ans = max(ans, cost);
    }

    cout << ans << endl;

    return 0;
}