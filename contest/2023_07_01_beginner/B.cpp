#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> c(105), d(105);
    vector<int> p(105);

    int ans = 0;
    for (int i = 1; i<= n; i++) cin >> c.at(i);
    for (int i = 1; i<= m; i++) cin >> d.at(i);
    for (int i = 0; i<= m; i++) cin >> p.at(i);

    for (int i = 1; i<= n; i++) {
        int j;
        for (j = 1; j <= m; j++) {
            if (c.at(i) == d.at(j)) {
                ans += p.at(j);
                break;
            }
        }
        if (j == m+1) ans += p.at(0);
    }

    cout << ans << endl;


    return 0; 
}