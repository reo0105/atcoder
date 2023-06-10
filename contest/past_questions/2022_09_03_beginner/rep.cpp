#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 2e18
typedef pair<ll, int> pl;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(200005);
    vector<ll> cost(200005, 0);
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<vector<int>> G(200005);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
        cost.at(u) += a.at(v);
        cost.at(v) += a.at(u);
    }

    // sort(cost.begin(), cost.end());

    ll l = -1, r = INF;
    while (r - l > 1) {
        queue<int> que;
        vector<ll> new_cost(200005, 0);
        vector<bool> done(200005, false);
        ll mid = (l + r) / 2;
        int cnt = 0;

        for (int i = 1; i <= n; i++) {
            new_cost.at(i) = cost.at(i);
            if (cost.at(i) <= mid) {
                que.push(i);
                done.at(i) = true;
                cnt++;
            }
        }

        while (que.size()) {
            int x = que.front();
            que.pop();

            for (int v : G.at(x)) {
                if (done.at(v)) continue;
                new_cost.at(v) -= a.at(x); 
                if (new_cost.at(v) <= mid) {
                    que.push(v);
                    done.at(v) = true;
                    cnt++;
                }
            }

            if (cnt == n) break;
        }

        if (cnt == n) r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}