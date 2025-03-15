#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x, y, n;
    cin >> x >> y >> n;

    int ans = 0;
    if (n >= 3 && 3*x > y) { ans += n/3 * y; n -= n/3*3; }

    ans += n * x;

    cout << ans << endl;

    return 0;
}