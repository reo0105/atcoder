#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    
    int n, m;
    cin >> n >> m;

    vector<vector<pii>> g(n);
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        a--; b--;
        g[a].push_back(make_pair(b, c));
        g[b].push_back(make_pair(a, c));
    }

    vector<int> ids(n);
    for (int i = 0; i < n; i++) ids[i] = i;

    int ans = 0;
    do {

        int t = 0;

        for (int i = 0; i < n-1; i++) {
            int u = ids[i], v = ids[i+1];

            bool exist = false;
            for (pii p : g[u]) {
                if (p.first == v) {
                    t += p.second;
                    // cout << u << " " << v << " " << t << endl;
                    exist = true;
                    break;
                }
            }
            if (!exist) break;
        }
        ans = max(ans, t);

    } while(next_permutation(ids.begin(), ids.end()));

    cout << ans << endl;

    return 0;
}