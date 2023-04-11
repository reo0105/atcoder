#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;

    vector<vector<int>> a(105, vector<int>(105));

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a.at(i).at(j);
        }
    }

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        ll s, t;
        int ok = 0;
        cin >> s >> t;
        s -= (s-1) / n * n;
        t -= (t-1) / n * n;
        // cout << s << " " << t << endl;

        vector<int> dist(105, -1);
        queue<int> que; 
        set<int> sel;
        
        for (int j = 1; j <= n; j++) {
            if (a.at(s).at(j) == 1) {
                dist.at(j) = 1;
                que.push(j);
            }
        }

        while (que.size()) {
            int top = que.front();
            que.pop();
            // cout << "top " << top << endl;

            for (int j = 1; j <= n; j++) {
                if (dist.at(j) != -1) continue;
                if (top == j) continue;
                if (a.at(top).at(j) == 1) {
                    // cout << j << " " << top << endl;
                    dist.at(j) = dist.at(top) + 1;
                    que.push(j);
                }
            }

            if (dist.at(t) != -1) {
                ok = 1;
                break;
            }
        }

        if (ok) cout << dist.at(t) << endl;
        else cout << -1 << endl;
        
    }

    return 0;
}