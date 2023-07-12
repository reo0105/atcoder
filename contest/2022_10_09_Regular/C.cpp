#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

vector<bool> seen(100005, false);
vector<vector<int>> G(100005);
vector<int> bs;
vector<int> as;
vector<vector<int>> id(100005);
vector<int> path;
int n, m , k;

// void dfs(int from, int par)
// {

//     for (int u : G.at(from)) {
//         if (u == par) continue;
//         if (seen.at(u)) continue;
//         // cout << from << " " << u << endl;

//         seen.at(u) = true;
//         path.push_back(u);
//         if (u == n) {
//             int now = 0;
//             int cnt = 0;
//             // cout << "arrived n\n";
//             vector<int> sub;
//             for (int x : path) sub.push_back(as.at(x-1));
//             int i = 0;
//             for (int b : bs) {
//                 for (; i < (int)sub.size(); i++) {
//                     if (b == sub.at(i)) {
//                         cnt++;
//                         break;
//                     }
//                 }
//             }
//             if (cnt != k) {
//                 cout << "No" << endl;
//                 exit(0);
//             }
//         }

//         if (u != n) dfs(u, from);
//         seen.at(u) = false;
//         path.pop_back();
//     }

// }

int main()
{
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    int INF = 1e9;
    vector<int> dist(100005, INF);
    priority_queue<pi, vector<pi>, greater<pi>> que;

    vector<int> a(100005);
    vector<int> b(100005);
    for (int i = 1; i <= n; i++) cin >> a.at(i);
    for (int i = 1; i <= k; i++) cin >> b.at(i);

    if (a.at(1) == b.at(1)) { que.push(make_pair(1, 1)); dist.at(1) = 1; }
    else { que.push(make_pair(0, 1)); dist.at(1) = 0; } 


    while (que.size()) {
        int d = que.top().first;
        int u = que.top().second;
        que.pop();

        if (d > dist.at(u)) continue;

        for (int v : G.at(u)) {
            int nd = d;
            if (a.at(v) == b.at(d+1)) nd++;
            if (nd < dist.at(v)) {
                dist.at(v) = nd;
                que.push(make_pair(nd, v));
            }
        }
    }

    // for (int i = 1; i <= n; i++) cout << dist.at(i) << " ";
    // cout << endl;

    if (dist.at(n) == k) cout << "Yes" << endl;
    else cout << "No" << endl;


    // for (int i = 1; i <= n; i++) {
    //     int a;
    //     cin >> a;
    //     as.push_back(a);
    //     id.at(a).push_back(i);
    // }
    // for (int i = 0; i < k; i++) {
    //     int t;
    //     cin >> t;
    //     bs.push_back(t);
    // }

    // seen.at(1) = true;
    // path.push_back(1);
    // dfs(1, -1);

    // cout << "Yes" << endl;

    return 0;
}