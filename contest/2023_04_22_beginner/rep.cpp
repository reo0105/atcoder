#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> G(2005);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    int k;
    cin >> k;

    string ans(n, '1');
    vector<int> p(2005), d(2005);

    for (int i = 0; i < k; i++) cin >> p.at(i) >> d.at(i);

    for (int i = 0; i < k; i++) {
        vector<int> dist(2005, -1);
        queue<int> que;


        dist.at(p.at(i)) = 0;
        que.push(p.at(i));
        if (d.at(i) != 0) ans.at(p.at(i)-1) = '0';

        while (que.size()) {
            int u = que.front();
            que.pop();

            if (dist.at(u) == d.at(i)) break;

            for (int v : G.at(u)) {
                if (dist.at(v) != -1) continue;

                dist.at(v) = dist.at(u) + 1;
                que.push(v);
                if (dist.at(v) < d.at(i)) ans.at(v-1) = '0';
            }
        }
    }

    int ok = 1;

    for (int i = 0; i < k; i++) {
        vector<int> dist(2005, -1);
        queue<int> que;

        dist.at(p.at(i)) = 0;
        que.push(p.at(i));

        if (d.at(i) == 0) {
            if (ans.at(p.at(i)-1) == '0') ok = 0;
            else continue;
            break;
        }

        int subok = 0;
        while (que.size()) {
            int u = que.front();
            que.pop();

            if (dist.at(u) == d.at(i)+1) break;

            for (int v : G.at(u)) {
                if (dist.at(v) != -1) continue;

                dist.at(v) = dist.at(u) + 1;
                que.push(v);

                if (dist.at(v) == d.at(i) && ans.at(v-1) == '1') { subok = 1; break; } 
            }
        }

        ok &= subok;
    }

    if (ok) {
        cout << "Yes" << endl;
        cout << ans << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}