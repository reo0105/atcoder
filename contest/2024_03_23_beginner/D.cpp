#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    ll ans = 1e18;
    
    for (int i = 0; i < n; i++) {
        if (i%2 == 1) s[i] ^= '0'^'1';
    }

    for (int i = 0; i < 2; i++) {
        vector<ll> l(n+1), r(n+1);
        for (int i = 0; i < n; i++) {
            l[i+1] = l[i];
            if (s[i] == '1') l[i+1] += c[i];
        }

        for (int i = n-1; i >= 0; i--) {
            r[i] = r[i+1];
            if (s[i] == '0') r[i] += c[i];
        }

        for (int i = 1; i < n; i++) {
            ans = min(ans, l[i] + r[i]);
        }

        for (int i = 0; i < n; i++) s[i] ^= '0'^'1';
    }

    cout << ans << endl;

    return 0;
}