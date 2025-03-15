#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(m), b(m);
    vector<vector<int>> G(n+1);

    for (int i = 0; i < m; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    for (int i = 0; i < m; i++) {
        G[a[i]].push_back(b[i]);
        G[b[i]].push_back(a[i]);
    }

    int ok = 1;
    vector<int> done(n+1, -1);
    for (int i = 1; i <= n; i++) {
        queue<int> que;

        if (done[i] == -1) {
            done[i] = 0;
            que.push(i);

            while (que.size()) {
                int u = que.front();
                int color = done[u];
                int next_color = color ^ 1;
                que.pop();
                
                for (int v : G[u]) {
                    if (done[u] == done[v]) { ok = 0; break; }
                    if (done[v] == -1) {
                        que.push(v);
                        done[v] = next_color;
                    }
                }
            }
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}