#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> edge;
#define INF 1<<29
//, G1(200002);
// vector<int> mv(200002, -1);
// vector<bool> s(200002, false);


int main()
{
    int n, m, k, u, v, a;
    deque<int> deq;
    vector<int> dist(400002);
    vector<vector<edge>> G(400002);

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        cin >> u >> v >> a;
        if (a == 1) {
            G.at(u).push_back(edge(v, 1));
            G.at(v).push_back(edge(u, 1));
        } else {
            G.at(u+n).push_back(edge(v+n, 1));
            G.at(v+n).push_back(edge(u+n, 1));
        }
    }

    for (int i = 0; i < k; i++) {
        int c;
        cin >> c;
        G.at(c).push_back(edge(c+n, 0));
        G.at(c+n).push_back(edge(c, 0));
    }

    for (int i = 1; i <= 2*n; i++) dist.at(i) = INF;
    
    dist.at(1) = 0;
    deq.push_back(1);

    while(!deq.empty()) {
        int from = deq.front();
        deq.pop_front();
        for (auto x : G.at(from)) {
            int next = x.first, c = x.second;
            if (dist.at(next) > dist.at(from) + c) {
                dist.at(next) = dist.at(from) + c;
                if (c == 1) deq.push_back(next);
                else deq.push_front(next);
            }
        }
    }

    int ans = min(dist.at(n), dist.at(2*n));

    if (ans == INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0;
}