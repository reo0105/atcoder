#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

/*
unordered_setは代替の操作が平均O(1)だから
vectorで判定した方が速いのかね？
*/

int main()
{
    int n, m;
    vector<int> a(200005);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<vector<int>> G(200005);
    vector<ll> cost(200005, 0);
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        cost.at(u) += a.at(v);
        cost.at(v) += a.at(u);
        // G.at(u).push_back(make_pair(v, a.at(v)));
        // G.at(v).push_back(make_pair(u, a.at(u)));
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    ll l = -1, r = 1e18;
    vector<ll> now_cost(200005);

    while (r - l > 1) {
        queue<int> que;
        // unordered_set<int> done;
        vector<bool> done(200005, false);
        ll mid = (l+r) / 2;

        for (int i = 1; i <= n; i++) {
            now_cost.at(i) = cost.at(i);
            if (cost.at(i) <= mid) {
                que.push(i);
                // done.insert(i);
                done.at(i) = true;
            }
        }

        int ok = 0;
        int cnt = (int)que.size();
        while (que.size()) {
            int x = que.front();
            que.pop();

            for (int v : G.at(x)) {
                now_cost.at(v) -= a.at(x);
                if (now_cost.at(v) <= mid && !done.at(v)) {
                    que.push(v);
                    // done.insert(v);
                    done.at(v) = true;
                    cnt++;
                } 
            }

            if (cnt == n) {
                ok = 1;
                break;
            }
        }

        // cout << l << " " << r << " " << cnt << endl;

        if (ok) r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}