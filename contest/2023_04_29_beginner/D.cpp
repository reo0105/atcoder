#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    ll ans = 0;

    vector<bool> isprime(1000005, true);
    vector<ll> prime;

    isprime.at(0) = false;
    isprime.at(1) = false;

    for (ll i = 2; i*i <= n; i++) {
        if (isprime.at(i)) {
            prime.push_back(i);
            for (ll j = 2; i*j <= 1000000; j++) {
                isprime.at(i*j) = false;
            }
        }
    }

    int sz = (int)prime.size();
    // cout << sz << endl;

    for (int ib = 1; ib < sz; ib++) {
        ll b = prime.at(ib);
        // if (n/(b*b*b) <= b) break;

        for (int ia = 0; ia < ib; ia++) {
            ll a = prime.at(ia);

            ll now = a * a * b;

            if (sqrt(n/now) <= b) break;

            ll maxi = sqrt(n/now);

            ll cnt = upper_bound(prime.begin(), prime.end(), maxi) - prime.begin() - ib -1;
            // cout << a << " "<< b << " " << cnt << endl;
            // cout << upper_bound(prime.begin(), prime.end(), maxi) << endl;
            
            ans += cnt;
        }
    } 

    cout << ans << endl;

    return 0;
}