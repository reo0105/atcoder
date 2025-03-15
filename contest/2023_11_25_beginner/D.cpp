#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];

    int ans = 0;

    vector<vector<int>> row(n);
    vector<vector<int>> col(n);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == 'o') {
                row[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[j][i] == 'o') {
                col[i].push_back(j);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] != 'o') continue;

            int x = (int)row[i].size() - 1;
            int y = (int)col[j].size() - 1;

            ans += x * y;
        }
    }

    cout << ans << endl;




    return 0;
}