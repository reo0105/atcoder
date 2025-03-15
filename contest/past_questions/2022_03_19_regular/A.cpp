#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll gcd(ll x, ll y)
{
    if (x < y) swap(x, y);
    ll res = x % y;

    while (res != 0) {
        ll tmp = y;
        y = x % y;
        x = tmp;
        res = x % y;
    }

    return y;
}

int main()
{
    ll l, r;
    cin >> l >> r;

    ll maxi = 0;

    for (ll i = l; i <= r; i++) {
        for (ll j = r; j >= l; j--) {
            if (j - maxi < l) break;
            if (gcd(i, j) == 1) {
                maxi = max(maxi, j-i);
                break;
            }
        }
        if (i+maxi > r) break;
    }

    cout << maxi << endl;

    return 0;
}