#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int h, w, n;
    cin >> h >> w >> n;

    // vector<int> a(n), b(n);
    vector<vector<int>> g(h+1, vector<int>(w+1, 0));
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        // a--; b--;
        g[a][b]++;
    }

    for (int i = 0; i <= h; i++) {
        for (int j = 0; j < w; j++) {
            g[i][j+1] += g[i][j];
        }
    }

    for (int j = 0; j <= w; j++) {
        for (int i = 0; i < h; i++) {
            g[i+1][j] += g[i][j];
        }
    }

    // vector<ll> cnt(3005, 0);
    // for (int i = 1; i <= min(h, w); i++) {
    //     cnt[i] = cnt[i-1] + (ll)i*i;
    // }
    // for (int i = 0; i <= h; i++) {
    //     for (int j = 0; j <= w; j++) {
    //         cout << g[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    ll ans = 0;
    for (int i = 1; i <= h; i++) {
        for (int j = 1; j <= w; j++) {
            int ac = -1, wa = 3005;

            // if (i == 0 && j == 0 && g[i][j] != 0) continue;
            // if (i != 0 && g[i][j] != g[i-1][j]) continue;
            // if (j != 0 && g[i][j] != g[i][j-1]) continue;
            while (wa - ac > 1) {
                int wj = (ac + wa) / 2;

                if (i+wj > h || j+wj > w) {
                    wa = wj;
                    continue;
                }
                int sum = g[i+wj][j+wj] - g[i-1][j+wj] - g[i+wj][j-1] + g[i-1][j-1];

                if (sum == 0) ac = wj;
                else wa = wj;
            }
            ans += ac+1;
            // cout << i << " " << j << " " << ac << endl;
        }
    }
    cout << ans << endl;


    return 0;
}