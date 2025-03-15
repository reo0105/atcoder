#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    ll xa, ya, xb, yb, xc, yc;

    cin >> xa >> ya >> xb >> yb >> xc >> yc;

    xa -= xc; xb -= xc;
    ya -= yc; yb -= yc;

    if (xb < 0) xa *= -1, xb *= -1;
    if (yb < 0) ya *= -1, yb *= -1;
    if (yb == 0) swap(xa, ya), swap(xb, yb);

    auto dist = [&](ll x, ll y) -> ll {
        if (xa == x && ya == y) return 0;
        ll res = abs(xa - x) + abs(ya-y);
        if (xa == x && xa == xb) {
            if ((ya < yb) != (y < yb)) res += 2;
        }
        if (ya == y && ya == yb) {
            if ((xa < xb) != (x < xb)) res += 2;
        }
        return res;
    };

    if (xb == 0) {
        ll ans = dist(xb, yb+1) + yb;
        cout << ans << endl;
        return 0;
    }

    ll ans = min(dist(xb, yb+1), dist(xb+1, yb));
    ans += xb+yb+2;
    cout << ans << endl;

    return 0;
}