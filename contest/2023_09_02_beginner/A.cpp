#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, p;
    cin >> n >> m >> p;

    int ans = 0;

    for (int i = 1; i <= n; i++) {
        if (i == m) ans++;
        if (i > m && (i - m) % p == 0) ans++;
    }

    cout << ans << endl;

    return 0;
}