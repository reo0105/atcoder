#include <bits/stdc++.h>

using namespace std;

bool check(int now, int n, vector<vector<char>>& ans, string r, string c, string base, vector<vector<int>>& ids, int cnt)
{
    if (now == n) {
        bool ok = true;
        for (int j = 0; j < n; j++) {
            for (int i = 0; i < n; i++) {
                if (ans[i][j] != '.') {
                    if (ans[i][j] != c[j]) ok = false;
                    break;
                }
            }
        }

        for (int j = 0; j < n; j++) {
            int cntA = 0, cntB = 0, cntC = 0;
            for (int i = 0; i < n; i++) {
                if (ans[i][j] == 'A') cntA++;
                if (ans[i][j] == 'B') cntB++;
                if (ans[i][j] == 'C') cntC++;
            }

            if (!(cntA == 1 && cntB == 1 && cntC == 1)) ok = false;
        }

        if (ok) return true;
        else return false;
    }
    
    for (int i = 0; i < cnt; i++) {
        vector<int> id = ids[i];
        
        bool ok = false;
        for (int j = 0; j < n; j++) {
            if (base[id[j]] != '.') {
                if (base[id[j]] == r[now]) ok = true;
                break;
            }
        }

        for (int j = 0; j < n; j++) ans[now][j] = base[id[j]];


        for (int j = 0; j < n; j++) {
            int cntA = 0, cntB = 0, cntC = 0;
            for (int k = 0; k < now; k++) {
                if (ans[k][j] == 'A') cntA++;
                if (ans[k][j] == 'B') cntB++;
                if (ans[k][j] == 'C') cntC++;
            }

            if (cntA > 1 || cntB > 1 || cntC > 1) ok = false;
        }

        if (ok) {
            if (check(now+1, n, ans, r, c, base, ids, cnt)) return true;
        }
    }

    return false;
}

int main()
{
    int n;
    string r, c;

    cin >> n >> r >> c;

    vector<int> id;
    vector<vector<int>> ids;
    string base = "ABC";

    for (int i = 0; i < n; i++) id.push_back(i);
    for (int i = 0; i < n-3; i++) base.push_back('.');

    int cnt = 0;
    do {
        ids.push_back(id);
        cnt++;
    } while (next_permutation(id.begin(), id.end()));

    vector<vector<char>> ans(n, vector<char>(n));

    if (check(0, n, ans, r, c, base, ids, cnt)) {
        cout << "Yes" << endl;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cout << ans[i][j];
            }
            cout << endl;
        }
    } else {
        cout << "No" << endl;
    }

    return 0;
}