#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;



int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> G(200005);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    priority_queue<pi> que;
    vector<int> dist(200005, -1);
    for (int i = 0; i < k; i++) {
        int p, h;
        cin >> p >> h;
        que.push(make_pair(h, p));
        dist.at(p) = h;
    }

    while (que.size()) {
        int u = que.top().second;
        int h = que.top().first;
        que.pop();

        if (dist.at(u) != h) continue;
        if (h == 0) continue;

        for (int v : G.at(u)) {
            if (dist.at(v) >= h-1) continue;
            dist.at(v) = h-1;
            que.push(make_pair(h-1, v));
        }
    }

    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        if (dist.at(i) != -1) ans.push_back(i);
    }

    cout << ans.size() << endl;
    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}