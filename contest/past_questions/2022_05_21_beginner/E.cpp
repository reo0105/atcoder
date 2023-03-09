#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;

struct Edge {
    int to;
    int num;
    long long cost;
    // bool operator< (Edge const& o) {
    //     return cost < o.cost;
    // }
};

int main()
{
    int v, e;
    int s, t, w;
    vector<vector<Edge>> edges(200005);

    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        cin >> s >> t >> w;
        struct Edge tmp;
        tmp.to = s; tmp.num = i+1; tmp.cost = w;
        edges.at(t).push_back(tmp);
        tmp.to = t;
        edges.at(s).push_back(tmp);
    }

    vector<ll> dist(200005, 1L<<58);
    vector<int> from(200005, -1);
    priority_queue<p, vector<p>, greater<p>> que;
    dist.at(1) = 0;
    que.push(make_pair(0, 1));

    while (!que.empty()) {
        ll c = que.top().first;
        int u = que.top().second;
        que.pop();

        if (c != dist.at(u)) continue;

        for (auto n : edges.at(u)) {
            ll nc = c + n.cost;
            int nv = n.to;
            if (nc < dist.at(nv)) {
                dist.at(nv) = nc;
                // cout << u << " " << nv << " " << n.cost << endl;;
                que.push(make_pair(nc, nv));
                from.at(nv) = n.num;
            }
        }
    }

    for (int i = 2; i <= v; i++) {
        cout << from.at(i) << " ";
    }
    cout << endl;
    return 0;
}