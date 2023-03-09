#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, x, y;
    int ans = 0;

    cin >> n >> x >> y;

    ll r = 1, b = 0;
    for (int i = 1; i < n; i++) {
        ll nr = r;
        b += x*r;
        nr += b;
        ll nb = b*y;
        r = nr;
        b = nb;
    }

    cout << b << endl;


    return 0;
}