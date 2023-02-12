#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, ans = 0;
    cin >> n >> m;
    vector<string> s(32);

    for (int i = 0; i < n; i++) cin >> s.at(i);

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int cnt = 0;
            for (int k = 0; k < m; k++) {
                if (s.at(i).at(k) == 'o' || s.at(j).at(k) == 'o') {
                    cnt++;
                } else {
                    break;
                }
            }
            if (cnt == m) ans++;
        }
    }

    cout << ans << endl;
    return 0;
}