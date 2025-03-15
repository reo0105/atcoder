#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    int q;
    int n = (int)s.size();

    cin >> s >> q;

    for (int i = 0; i < q; i++) {
        ll t, k;
        ll root;
        cin >> t >> k;
        k--;
        if (t < 60) {
            ll b = 1L << t;
            root = k/b;
            k %= b;
        } else {
            root = 0;
        }

        ll r = 0;
        for (int i = 0; i <= 60; i++) {
            if ((k >> i) & 1) r++;
        }
        ll l = t - r;
        ll x = l+r*2 + (s.at(root) - 'A');
        char ans = 'A'+(x%3);
        cout << ans << endl;
    }

    return 0;
}