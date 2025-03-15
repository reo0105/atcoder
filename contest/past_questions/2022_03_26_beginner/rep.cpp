#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

vector<vector<int>> G(200005);
vector<int> dist(200005, -1);
vector<bool> finished(200005, false);
int cnt = 0;

void dfs(int from)
{  
    dist.at(from) = 0;

    for (int v : G.at(from)) {
        if (dist.at(v) == -1) {
            dfs(v);
        }

        if (dist.at(v) == 2 || dist.at(v) == 0) {
            dist.at(from) = 2;
        } 
    }

    if (dist.at(from) == 0) dist.at(from) = 1;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (dist.at(i) == -1) {
            dfs(i);
        }
    }

    for (int i = 1; i <= n; i++) {
        if (dist.at(i) == 2) ans++;
    }

    cout << ans << endl;

    return 0;
}