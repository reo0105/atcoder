#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void dfs(vector<vector<int>>& G, vector<bool>& seen, int& now_c, vector<int>& sz, int from)
{
    seen[from] = true;
    
    for (int u : G[from]) {
        if (seen[u]) continue;

        seen[u] = true;
        now_c++;
        dfs(G, seen, now_c, sz, u);
        if (from == 1) {
            sz.push_back(now_c);
            now_c = 0;
        }
    }
}

int main() 
{
    int n;
    cin >> n;

    vector<vector<int>> G(n+1);

    vector<int> sz;

    for (int i = 0; i < n-1; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }

    if ((int)G[1].size() == 1) {
        cout << 1 << endl;
        return 0;
    }

    int now_c = 0;
    int ans = 1;
    vector<bool> seen(n+1, false);

    dfs(G, seen, now_c, sz, 1);

    sort(sz.begin(), sz.end());

    for (int i = 0; i < (int)sz.size()-1; i++) {
        ans += sz[i];
    }

    cout << ans << endl;

    return 0;

}