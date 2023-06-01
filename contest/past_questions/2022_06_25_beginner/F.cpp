#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;
int main()
{
    int n, m;
    vector<vector<int>> G(300005);
    vector<int> undeside;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == 0) undeside.push_back(v);
        else {
            G.at(u).push_back(v);
            G.at(v).push_back(u);
        }
    }
    vector<int> dist1(300005, -1);
    vector<int> distn(300005, -1);
    queue<int> que;
    dist1.at(1) = 0;
    que.push(1);
    
    while (que.size()) {
        int u = que.front();
        que.pop();
        for (int v : G.at(u)) {
            if (dist1.at(v) != -1) continue;
            dist1.at(v) = dist1.at(u) + 1;
            que.push(v);
        }
    }
    
    distn.at(n) = 0;
    que.push(n);
    
    while (que.size()) {
        int u = que.front();
        que.pop();
        for (int v : G.at(u)) {
            if (distn.at(v) != -1) continue;
            distn.at(v) = distn.at(u) + 1;
            que.push(v);
        }
    }
    
    //1とnが含まれる連結成分だけを考えてそこに行先未定があるか
    // set<int> undef1, undefn;
    int min1 = 1e9, minn = 1e9;
    for (int v : undeside) {
        if (dist1.at(v) != -1 && dist1.at(v) < min1) {
            min1 = dist1.at(v);
        }
        if (distn.at(v) != -1 && distn.at(v) < minn) {
            minn = distn.at(v);
        } 
    }

    // cout << min1 << " " << minn << endl;
    // for (int i = 1; i <= n; i++) cout << dist1.at(i) << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << distn.at(i) << " ";
    // cout << endl;

    for (int i = 1; i <= n; i++) {
        int ans = 1e9;
        if (min1 != 1e9 && distn.at(i) != -1) {
            // ok
            int d = distn.at(i) + 1 + min1;
            ans = min(ans, d);
            // cout << "case 1 " << ans << endl;
        } 
        if (minn != 1e9 && dist1.at(i) != -1) {
            //ok
            int d = dist1.at(i) + 1 + minn;
            ans = min(ans, d);
            // cout << "case 2 " << ans << endl;
        } 
        if (min1 != 1e9 && minn != 1e9) {
            int d = min1 + minn + 2;
            ans = min(ans, d);
        }
        if (dist1.at(n) != -1) {
            // ok
            ans = min(ans, dist1.at(n));
            // cout << "case 3 " << ans << endl;
        }

        if (ans == 1e9) cout << -1 << endl;
        else cout << ans << endl;
    }

    return 0;
}