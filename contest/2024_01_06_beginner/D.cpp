#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> ans(n, vector<int>(n, -1));

    int ni = 0, nj = 0;
    int cnt = 1;
    int fi = (n+1) / 2, fj = (n+1) / 2;
    while (ni != fi && nj != fj) {

        for (int j = 0; j <= n; j++) {
            if (nj < n && ans[ni][nj] == -1) {
                ans[ni][nj] = cnt;
                nj++;
                cnt++;
            } else {
                nj--;
                break;
            }
        }
        ni++;
        for (int i = 0; i <= n; i++) {
            if (ni < n && ans[ni][nj] == -1) {
                ans[ni][nj] = cnt;
                ni++;
                cnt++;
            } else {
                ni--;
                break;
            }
        }

        nj--;
        for (int j = 0; j <= n; j++) {
            if (nj >= 0 && ans[ni][nj] == -1) {
                ans[ni][nj] = cnt;
                nj--;
                cnt++;
            } else {
                nj++;
                break;
            }
        }

        ni--;
        for (int i = 0; i <= n; i++) {
            if (ni >= 0 && ans[ni][nj] == -1) {
                ans[ni][nj] = cnt;
                ni--;
                cnt++;
            } else {
                ni++;
                break;
            }
        }

        nj++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == fi-1 && j == fj-1) cout << "T ";
            else cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    

    return 0;
}