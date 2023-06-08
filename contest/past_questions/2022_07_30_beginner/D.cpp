#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    ll x = 2*b - a - c;

    if (x >= 0) cout << 2*b - a - c << endl;
    else {
        if (-x % 2 == 1) {
            x--;
            cout << -x / 2 + 1 << endl;
        } else {
            cout << -x / 2 << endl;
        }
    }

    return 0;

}