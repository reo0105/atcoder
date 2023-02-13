#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int n, m;
    int flag = 1;
    vector<vector<int>> G(200005);

    cin >> n >> m;
    
    if (n-m != 1) flag = 0;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    int from = 1;
    for (int i = 1; i <= n; i++) {
        if ((int)G.at(i).size() == 1) {
            from = i;
            // cout << from;
            
        }
    }

    vector<int> dist(200005, -1);
    queue<int> que;
    que.push(from);
    dist.at(from) = 1;

    while(!que.empty()) {
        int u = que.front();
        que.pop();

        for (int v : G.at(u)) {
            if (dist.at(v) != -1) continue;
            dist.at(v) = dist.at(u) + 1;
            que.push(v);
        }
    }

    // cout << from << endl;
    int i;
    for (i = 1; i <= n; i++) {
        // cout << dist.at(i) << " "; 
        if (dist.at(i) == n)  break;
    }

    if (i == n+1) flag = 0;


    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}