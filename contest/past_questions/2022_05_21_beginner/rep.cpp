#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, int> p;
#define INF 1L<<58

struct edge {
    // int from;
    int to;
    int cost;
    int id;
    // bool operator< (edge const& o) {
        // return cost < o.cost;
    // }
};

int main()
{
    int n, m;
    vector<vector<edge>> G(200005);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        edge tmp;
        cin >> a >> b >> c;
        tmp.to = b; tmp.cost = c; tmp.id = i+1;
        G.at(a).push_back(tmp);
        tmp.to = a;
        G.at(b).push_back(tmp);
    }

    vector<ll> dist(200005, INF);
    priority_queue<p, vector<p>, greater<p>> que;
    vector<int> ans(200005);

    dist.at(1) = 0;
    que.push(make_pair(0, 1));

    while (que.size()) {
        p top = que.top();
        que.pop();
        ll c = top.first;
        int u = top.second;

        if (dist.at(u) < c) continue;

        for (auto v : G.at(u)) {
            ll nc = c + v.cost;
            if (dist.at(v.to) <= nc) continue;
            dist.at(v.to) = nc;
            que.push(make_pair(nc, v.to));
            ans.at(v.to) = v.id;
        }
    }

    for (int i = 2; i <= n; i++) cout << ans.at(i) << " ";
    cout << endl;

    return 0;
}