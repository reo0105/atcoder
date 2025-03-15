#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n, m;
    cin >> n >> m;
    string ans, zero;
    for (int i = 0; i < n; i++) {
        ans.push_back('1');
        zero.push_back('0');
    }

    vector<vector<int>> G(2005);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }


    int k;
    cin >> k;
    vector<int> d(2005, -1);

    for (int i = 1; i <= k; i++) {
        int pi, di;
        cin >> pi >> di;
        d.at(pi) = di;
    }

    vector<vector<int>> dist(2005, vector<int> (2005, -1));


    for (int i = 1; i <= n; i++) {
        queue<int> que;
        dist.at(i).at(i) = 0;
        que.push(i);

        while (que.size()) {
            int u = que.front();
            que.pop();

            for (int v : G.at(u)) {
                if (dist.at(i).at(v) != -1) continue;
                dist.at(i).at(v) = dist.at(i).at(u) + 1;
                que.push(v);
            }
        }
    }

    int flag = 1;
    for (int i = 1; i <= n; i++) {
        if (d.at(i) == -1) continue;
        for (int j = 1; j <= n; j++) {
            if (dist.at(i).at(j) < d.at(i)) ans.at(j-1) = '0';
        }
    }

    for (int i = 1; i <= n; i++) {
        if (d.at(i) == -1) continue;
        if (d.at(i) == 0) {
            if (ans.at(i-1) == '0') {flag = 0; break;}
            else continue;
        } else {
            if (ans.at(i-1) == '1') {flag = 0; break;}
        }
        queue<int> que;
        vector<int> dist(2005, -1);
        que.push(i);
        dist.at(i) = 0;

        int eq = 0;
        while (que.size()) {
            int u = que.front();
            que.pop();

            for (int v : G.at(u)) {
                if (dist.at(v) != -1) continue;
                dist.at(v) = dist.at(u) + 1;
                que.push(v);
                if (dist.at(v) < d.at(i) && ans.at(v-1) == '1') flag = 0;
                else if (dist.at(v) == d.at(i) && ans.at(v-1) == '1') eq++;
                else if (dist.at(v) > d.at(i) && eq == 0) flag = 0;
            }
        }
    }


    if (flag == 0 || ans == zero) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        cout << ans << endl;
    }

    return 0;
}