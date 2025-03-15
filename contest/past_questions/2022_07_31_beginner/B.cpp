#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(105);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        G.at(u).push_back(v);
        G.at(v).push_back(u);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int u : G.at(i)) {
            for (int v : G.at(u)) {
                for (int i0 : G.at(v)) {
                    if (i == i0) ans++;
                }
            }
        }
    }

    cout << ans / 6 << endl;

    return 0;
}