#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, x, t, d;
    cin >> n >> m >> x >> t >> d;

    int s;
    if (n <= x) s = t - d*n;
    else s = t - d*x;

    if (m <= x) cout << s + d*m << endl;
    else cout << s + d*x << endl;

    return 0;
}