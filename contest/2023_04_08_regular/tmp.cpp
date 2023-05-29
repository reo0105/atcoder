#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b;

    cin >> a >> b;
    if (a > b) swap(a, b);
    ll diff = b-a;
    
    ll ans = 0;
    while (a) {
        ll g = gcd(a, b);

        diff /= g;

        vector<ll> divs;

        for (ll i = 1; i * i <= diff; i++) {
            if (diff % i == 0) {
                divs.push_back(i*g);
                divs.push_back(diff / i * g);
            }
        }

        ll next = 1e18;
        for (ll d : divs) {
            if (d == g) continue;
            next = min(next, a - a / d * d);
        }

        ans += next;

        a -= next * g;
        b = a + diff;
    }

    cout << ans << endl;
}