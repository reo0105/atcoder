#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll d;
    cin >> d;

    ll ans = d;
    for (ll x = 0; x <= sqrt(d); x++) {
        ll temp_y = abs(x*x - d);

        ll sq_y = sqrt(temp_y);


        for (int i = -2; i <= 2; i++) {
            ll y = sq_y + i;
            if (y < 0) continue;

            ans = min(abs(x*x+y*y - d), ans);
        }
    }

    cout << ans << endl;

    return 0;
}