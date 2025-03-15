#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, p, q;
    cin >> n >> p >> q;

    int ans = p;
    for (int i = 0; i < n; i++) {
        int d;
        cin >> d;
        ans = min(ans, q+d);
    }

    cout << ans << endl;

    return 0;
}