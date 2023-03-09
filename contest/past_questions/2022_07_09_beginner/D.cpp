#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, cnt = 0;
    int sx, sy, tx, ty;
    vector<int> s;
    set<int> e;
    vector<ll> x(3005), y(3005), r(3005);
    vector<vector<int>> G(3005);

    cin >> n >> sx >> sy >> tx >> ty;
    for (int i = 1; i <= n; i++) cin >> x.at(i) >> y.at(i) >> r.at(i);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            ll d = (x.at(i) - x.at(j)) * (x.at(i) - x.at(j)) + (y.at(i) - y.at(j)) * (y.at(i) - y.at(j));
            ll diff = abs((r.at(i) - r.at(j)) * (r.at(i) - r.at(j)));
            ll sum = (r.at(i) + r.at(j)) * (r.at(i) + r.at(j));
            if (diff <= d && d <= sum) {
                G.at(i).push_back(j);
                G.at(j).push_back(i);
            }
        }

        if ((x.at(i) - sx) * (x.at(i) - sx) + (y.at(i) - sy) * (y.at(i) - sy) == r.at(i)*r.at(i)) {
            s.push_back(i);
        } 
        if ((x.at(i) - tx) * (x.at(i) - tx) + (y.at(i) - ty) * (y.at(i) - ty) == r.at(i)*r.at(i)) {
            e.insert(i);
        }
    }

    int flag = 0;

    // cout << s.size() << " " << e.size() << endl;

    for (int s0 : s) {

        if (e.count(s0)) {
            flag = 1;
            goto out;
        }

        queue<int> que;
        vector<bool> seen(3005, false);
        que.push(s0);
        seen.at(s0) = true;

        while(!que.empty()) {
            int u = que.front();
            que.pop();

            for (int v : G.at(u)) {
                if (seen.at(v)) continue;

                que.push(v);
                seen.at(v) = true;
                if (e.count(v)) {
                    flag = 1;
                    goto out;
                }
            }
        }
    }
out:
    // cout << s << " " << e << endl;

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}