#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b;
    cin >> a >> b;

    ll ans = 0;

    while (a != b) {
        if (a > b) swap(a, b);

        ll cnt = (b-1) / a ;
        ans += cnt;
        b -= a*cnt;
        // cout << a << " " << b << endl;
    }

    cout << ans << endl;

    return 0;
}