#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, w;
    int r, c;
    int ans = 0;
    cin >> h >> w >> r >> c;

    if (r-1 >= 1) ans++;
    if (r+1 <= h) ans++;
    if (c-1 >= 1) ans++;
    if (c+1 <= w) ans++;

    cout << ans << endl;

    return 0;
}