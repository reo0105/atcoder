#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w, k;
    cin >> h >> w >> k;

    vector<string> s(h);

    for (int i = 0; i < h; i++) cin >> s[i];

    vector<vector<int>> os_row(h, vector<int>(w+1, 0));
    vector<vector<int>> xs_row(h, vector<int>(w+1, 0));

    vector<vector<int>> os_col(w, vector<int>(h+1, 0));
    vector<vector<int>> xs_col(w, vector<int>(h+1, 0));


    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == 'o') {
                os_row[i][j+1] = os_row[i][j] + 1;
                xs_row[i][j+1] = xs_row[i][j];
            } else if (s[i][j] == 'x') {
                os_row[i][j+1] = os_row[i][j];
                xs_row[i][j+1] = xs_row[i][j] + 1;
            } else {
                os_row[i][j+1] = os_row[i][j];
                xs_row[i][j+1] = xs_row[i][j];
            }
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j < h; j++) {
            if (s[j][i] == 'o') {
                os_col[i][j+1] = os_col[i][j] + 1;
                xs_col[i][j+1] = xs_col[i][j];
            } else if (s[j][i] == 'x') {
                os_col[i][j+1] = os_col[i][j];
                xs_col[i][j+1] = xs_col[i][j] + 1;
            } else {
                os_col[i][j+1] = os_col[i][j];
                xs_col[i][j+1] = xs_col[i][j];
            }
        }
    }

    int ans = 1e9;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j <= w-k; j++) {
            if (xs_row[i][j+k] - xs_row[i][j] == 0) {
                ans = min(ans, k-(os_row[i][j+k]-os_row[i][j]));
            }
        }
    }

    for (int i = 0; i < w; i++) {
        for (int j = 0; j <= h-k; j++) {
            if (xs_col[i][j+k] - xs_col[i][j] == 0) {
                ans = min(ans, k-(os_col[i][j+k]-os_col[i][j]));
            }
        }
    }

    if (ans == 1e9) ans = -1;

    cout << ans << endl;

    return 0;
}