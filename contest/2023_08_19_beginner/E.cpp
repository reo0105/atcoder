#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> g(n+1);
    for (int i = 1; i <= n; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int p;
            cin >> p;
            g[i].push_back(p);
        }
    }

    vector<bool> seen(n+1, false);
    auto dfs = [&](auto dfs, int from) -> void {
        seen[from] = true;

        for (int u : g[from]) {
            if (!seen[u]) dfs(dfs, u);
        }

        if (from != 1) cout << from << " ";
    };

    dfs(dfs, 1);
    cout << endl;

    return 0;
}