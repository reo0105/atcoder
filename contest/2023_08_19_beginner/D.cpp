#include <bits/stdc++.h>
using namespace std;

int main() {
    int h, w;
    cin >> h >> w;
    
    vector<string> c(h);
    for (int i = 0; i < h; i++) cin >> c[i];
    
    vector<vector<int>> a(h, vector<int>(w));
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            a[i][j] = c[i][j] - 'a';
        }
    }

    const int m = 26;
    vector<vector<int>> row(h, vector<int>(m));
    vector<vector<int>> col(w, vector<int>(m));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            row[i][a[i][j]]++;
            col[j][a[i][j]]++;
        }
    }
    bool upd = true;

    vector<bool> row_deleted(h);
    vector<bool> col_deleted(w);

    auto toDelete = [&](vector<int> x) {
        int tot = 0, k = 0;
        for (int j = 0; j < m; j++) {
            tot += x[j];
            if (x[j]) k++;
        }
        return tot >= 2 && k == 1;
    };

    auto del = [&](int i, int j) {
        if (row_deleted[i] || col_deleted[j]) return;
        row[i][a[i][j]]--;
        col[j][a[i][j]]--;
    };

    while (upd) {
        upd = false;
        vector<int> del_row, del_col;
        for (int i = 0; i < h; i++) {
            if (row_deleted[i]) continue;
            if (toDelete(row[i])) del_row.push_back(i);
        }
        for (int i = 0; i < w; i++) {
            if (col_deleted[i]) continue;
            if (toDelete(col[i])) del_col.push_back(i);
        }
        for (int i : del_row) {
            for (int j = 0; j < w; j++) {
                del(i, j);
            }
            row_deleted[i] = true;
            upd = true;
        }
        for (int i : del_col) {
            for (int j = 0; j < h; j++) {
                del(j, i);
            }
            col_deleted[i] = true;
            upd = true;
        }
    }

    int ans = 0;
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (row_deleted[i] || col_deleted[j]) continue;
            ans++;
        }
    }
    cout << ans << endl;

    return 0;

}