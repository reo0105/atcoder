#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> keys(m, vector<int>(n, 0));
    vector<int> open(m, 0);

    for (int i = 0; i < m; i++) {
        int c;
        cin >> c;
        for (int j = 0; j < c; j++) {
            int x;
            cin >> x;
            keys[i][x-1] = 1;
        }
        char r;
        cin >> r;
        open[i] = (r == 'o');
    }

    int ans = 0;

    for (int s = 0; s < (1<<n); s++) {
        // int cnt = 0;
        // for (int j = 0; j < n; j++) {
        //     if ((s >> j) & 1) cnt++;
        // }

        // if (cnt < k) continue;

        int ok = 1;

        for (int i = 0; i < m; i++) {
            int same = 0;

            for (int j = 0; j < n; j++) {
                if (keys[i][j] && ((s>>j) & 1)) same++;
            }

            if (same >= k && !open[i]) ok = 0;
            else if (same < k && open[i]) ok = 0;
        }

        if (ok) ans++;

    }

    cout << ans << endl;

    return 0;
}