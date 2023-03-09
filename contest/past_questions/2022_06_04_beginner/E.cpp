#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n, m, q;
    vector<vector<int>> G(200000);
    vector<vector<int>> dist(4, vector<int>(200000, 0));

    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

 

    for (int i = 1; i <= n; i++) {
        queue<p> que;
        set<int> done;
        que.push(make_pair(i, 0));
        done.insert(i);

        while (!que.empty()) {
            int u = que.front().first;
            int c = que.front().second;
            que.pop();
            if (c == 3) break;
            for (int v : G.at(u)) {
                if (done.count(v)) continue;
                int nc = c + 1;
                done.insert(v);
                // if (i == 2) cout << nc << " " << v << endl;
                dist.at(nc).at(i) += v;
                que.push(make_pair(v, nc));
            }
        }
    }

    for (int j = 0; j < 4; j++) {
        for (int i = 1; i <= n; i++) {
            if (j == 0) dist.at(j).at(i) = i;
            else dist.at(j).at(i) += dist.at(j-1).at(i);
        }
    }


    cin >> q;
    for (int i = 0; i < q; i++) {
        int x, k;
        cin >> x >> k;
        cout << dist.at(k).at(x) << endl;
    }

    return 0;
}