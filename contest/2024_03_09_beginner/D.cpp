#include <bits/stdc++.h>
using namespace std;

int main()
{
    string t;
    cin >> t;

    int n;
    cin >> n;

    vector<vector<string>> s(n+1);
    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            string temp;
            cin >> temp;
            s[i].push_back(temp);
        }
    }


    int tlen = (int)t.size();
    vector<vector<int>> dp(n+5, vector<int>(tlen+5, 1e9));

    dp[0][0] = 0;


    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < tlen; j++) {
            dp[i][j] = min(dp[i-1][j], dp[i][j]);
            for (int k = 0; k < (int)s[i].size(); k++) {
                int ok = 1;
                for (int l = 0; l < (int)s[i][k].size(); l++) {
                    if (j+l >= tlen) { ok = 0; break; }
                    if (t[j+l] != s[i][k][l]) ok = 0;
                }
                if (ok == 0) continue;

                dp[i][j+(int)s[i][k].size()] = min(dp[i][j+(int)s[i][k].size()], dp[i-1][j] + 1);
            }
        }
    }

    for (int i = 1; i < n; i++) dp[i+1][tlen] = min(dp[i+1][tlen], dp[i][tlen]);
    int ans = dp[n][tlen];

    if (ans == 1e9) ans = -1;

    cout << ans << endl;

    return 0;
}