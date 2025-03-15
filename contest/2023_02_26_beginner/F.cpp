#include <bits/stdc++.h>
using namespace std;
#define INF 1<<29

int main()
{
    int n, m;
    vector<string> s(100005);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> s.at(i);

    vector<int> dp1(100005, INF);
    vector<int> dpn(100005, INF);

    dp1.at(1) = 0;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= min(i-1, m); j++) {
            if (s.at(i-j).at(j-1) == '1') {
                dp1.at(i) = min(dp1.at(i), dp1.at(i-j) + 1);
            }
        }
    }

    dpn.at(n) = 0;
    for (int i = n-1; i >= 1; i--) {
        for (int j = 1; j <= min(m, n-i); j++) {
            if (s.at(i).at(j-1) == '1') {
                dpn.at(i) = min(dpn.at(i), dpn.at(i+j) + 1);
            }
        }
    }

    for (int i = 2; i <= n-1; i++) {
        int ans = INF;
        for (int j = i-m; j < i; j++) {
            if (j < 1) continue;
            for (int k = i+1; k <= i+m; k++) {
                if (k > n || k-j > m) break;
                if (s.at(j).at(k-j-1) == '1') {
                    ans = min(ans, dp1.at(j)+dpn.at(k)+1);
                }
            }
        }
        if (ans == INF) ans = -1;
        cout << ans << " ";
    }
    cout << endl;
     
    return 0;
}