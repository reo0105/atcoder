#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<vector<int>> p(105);

    for (int i = 0; i < 2*n; i++) {
        int a;
        cin >> a;
        p[a].push_back(i);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(p[i][0] - p[i][1]) == 2) ans++;
    }

    cout << ans << endl;
    return 0;
}