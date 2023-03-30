#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1L<<58

int main()
{
    int n, m;
    vector<vector<ll>> edge(305, vector<ll>(305, INF));
    vector<vector<ll>> dist(305, vector<ll>(305, INF));

    cin >> n >> m;
    for (int i = 0; i <= n; i++) dist.at(i).at(i) = 0;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        edge.at(a).at(b) = c;
        dist.at(a).at(b) = c;
        dist.at(b).at(a) = c; 
    }

    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                dist.at(i).at(j) = min(dist.at(i).at(j), dist.at(i).at(k) + dist.at(k).at(j));
            }
        }
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (edge.at(i).at(j) != INF) {
                int erase = 0;
                for (int k = 1; k <= n; k++) {
                    if (k == i || k == j) continue;
                    if (dist.at(i).at(k) + dist.at(k).at(j) <= edge.at(i).at(j)) erase = 1;
                }

                if (erase) ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}