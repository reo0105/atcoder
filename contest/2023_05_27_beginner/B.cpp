#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    vector<vector<bool>> ok(55, vector<bool>(55, true));

    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int pre;
        cin >> pre;
        for (int i = 0; i < n-1; i++) {
            int now;
            cin >> now;
            ok.at(pre).at(now) = false;
            ok.at(now).at(pre) = false;
            pre = now;
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i == j) continue;
            if (ok.at(i).at(j)) cnt++;
        }
    }

    cout << cnt/2 << endl;

    return 0;
}