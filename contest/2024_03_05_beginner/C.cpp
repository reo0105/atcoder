#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    ll ans = 1;

    for (ll i = 1; i*i*i <= n; i++) {
        ll k = i*i*i;

        string s = to_string(k);
        int l = (int)s.size();

        int ok = 1;
        for (int j = 0; j < l/2; j++) {
            if (s[j] != s[l-j-1]) ok = 0;
        }

        if (ok) ans = max(ans, k);
    } 

    cout << ans << endl;

    return 0;
}