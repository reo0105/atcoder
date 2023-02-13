#include <bits/stdc++.h>
using namespace std;
#define INF 1<<29
typedef pair<int, bool> pb;
typedef pair<int, int> pi;


int main()
{
    int t;
    int n, m, u, v;
    vector<int> c(2005);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n >> m;
        for (int j = 1; j <= n; j++) cin >> c.at(j);

        vector<vector<int>> G(2005);
        for (int j = 0; j < m; j++) {
            cin >> u >> v;
            G.at(u).push_back(v);
            G.at(v).push_back(u);
        }

        vector<vector<int>> dist(2005, vector<int>(2, -1));
        queue<tuple<int, int, int>> que;
        
        dist.at(1).at(0) = 0;
        dist.at(n).at(1) = 0;
        que.push(make_tuple(1, n, 0));
        
        int ans = -1;
        set<pi> done;
        while(!que.empty()) {
            tuple<int, int, int> tmp = que.front();
            int takahasi = get<0>(tmp);
            int aoki = get<1>(tmp);
            int cnt = get<2>(tmp);
            que.pop();

            for (int tn : G.at(takahasi)) {
                for (int an : G.at(aoki)) {
                    if (c.at(tn) != c.at(an) && !done.count(make_pair(tn, an))) {
                        que.push(make_tuple(tn, an, cnt+1));
                        done.insert(make_pair(tn, an));
                        if (tn == n && an == 1) {ans = cnt + 1; goto end;}
                    }
                }
            }
        }
end:
        cout << ans << endl;
    }

    return 0;
}