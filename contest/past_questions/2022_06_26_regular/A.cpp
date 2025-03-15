#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    if (a > b) swap(a, b);
    if (b > c) swap(b, c);

    ll ans = 0;
    if (c- b > a) cout << -1 << endl;
    else {
        // a -= (c-b);
        // c -= (c-b);
        ans = (c-b) + (b-a) + a;
        cout << ans << endl;
    }


    return 0;
}