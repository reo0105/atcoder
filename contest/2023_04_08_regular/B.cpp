#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b;
    cin >> a >> b;

    if (a > b) swap(a, b);

    ll ans = 0;

    while (a) {
        ll g = gcd(a, b);

        ll diff = b-a;
        diff /= g;

        vector<ll> divs;

        for (ll i = 1; i*i <= diff; i++) {
            if (diff % i == 0) {
                divs.push_back(i*g);
                divs.push_back(diff / i * g);
            }
        }

        ll maxi = 0;

        for (ll d : divs) {
            if (d == g) continue;
            ll tmp = a / d * d;
            maxi = max(maxi, tmp);
        }

        ans += (a - maxi) / g;

        a = maxi;
        b = a + diff * g;
    }

    cout << ans << endl;

    return 0;
}

