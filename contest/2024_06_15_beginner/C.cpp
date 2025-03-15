#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> str(n);
    for (int i = 0; i < n; i++) cin >> str[i];

    int ans = 10;
    int all = (1<<m)-1;

    for (int s = 1; s < (1<<n); s++) {
        int now = 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if ((s>>i) & 1) {

                for (int j = 0; j < m; j++) {
                    if (str[i][j] == 'o') now |= 1<<j;
                }

                cnt++;
                if (now == all) {
                    ans = min(ans, cnt);
                    break;
                }
            }
        }
    }

    cout << ans << endl;

}