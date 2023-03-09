#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    vector<int> a(105), b(105);
    int ans = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a.at(i);
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;
        ans += a.at(b);
    }

    cout << ans << endl;


    return 0;
}