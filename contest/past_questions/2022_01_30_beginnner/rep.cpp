#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define INF 1<<29

struct edge {
    int to;
    int cost;
};

vector<vector<edge>> G(200005);
vector<int> dist (200005, INF);

void dijkstra()
{
    priority_queue<p, vector<p>, greater<p>> que;
    dist.at(1) = 0;
    que.push(make_pair(0, 1));

    while (!que.empty()) {
        int d = que.top().first;
        int u = que.top().second;
        que.pop();
        if (dist.at(u) < d) continue;
        for (edge v : G.at(u)) {
            int c = d + v.cost;
            if (dist.at(v.to) > c) {
                dist.at(v.to) = c;
                que.push(make_pair(c, v.to));
            }
        }
    }
}


int main()
{
    int n, m;
    vector<int> h(200005);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> h.at(i);

    for (int i = 0; i < m; i++) {
        int u, v;
        edge tmp;
        cin >> u >> v;
        if (h.at(u) < h.at(v)) swap(u, v);
        tmp.to = v; tmp.cost = 0;
        G.at(u).push_back(tmp);
        tmp.to = u; tmp.cost = (h.at(u) - h.at(v));
        G.at(v).push_back(tmp);
    }

    dijkstra();

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, h.at(1) - h.at(i) - dist.at(i));
        // cout << dist.at(i) << " ";
    }

    cout << ans << endl;

    return 0;
}