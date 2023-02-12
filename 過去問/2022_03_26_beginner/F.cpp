#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(200005);
vector<int> dist(200005, -1); //0:探索中、 1:不可能、　2:可能
vector<bool> seen(200005, false);
vector<int> pre(200005);
set<int> loop;
int ind = 0;


void dfs(int from)
{
    seen.at(from) = true;
    dist.at(from) = 0;
    pre.at(ind) = from;
    ind++;

    for (int v : G.at(from)) {
        if (dist.at(v) == -1) {
            dfs(v);
        }
        if (dist.at(v) == 0 || dist.at(v) == 2) {
            dist.at(from) = 2;
        }
    }

    if (dist.at(from) == 0) dist.at(from) = 1; 

    ind--;
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

    for (int i = 1; i <= n; i++) {
        if (!seen.at(i)) {
            dfs(i);
        }
    }

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if(dist.at(i) == 2) ans++;
    }

    cout << ans << endl;

    return 0;
}