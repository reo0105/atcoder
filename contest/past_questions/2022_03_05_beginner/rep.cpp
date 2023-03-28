#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    string s;
    int q;

    cin >> s >> q;
    int n = (int)s.size();

    for (int i = 0; i < q; i++) {
        ll t, k;
        cin >> t >> k;

        ll s0;
        if (t > 59) {
            s0 = 0;
        } else {
            s0 = (k-1) / (1L<<t);
            k -= (1L<<t) * s0;
        }

        // t %= 3; k %= 3;
        // cout << s0 << " " << k << endl;
        ll cnt = s.at(s0) - 'A';
        cnt = cnt + t % 3;
        cnt = cnt + k % 3;
        if (cnt == 0) cout << 'A' << endl;
        else if (cnt == 1) cout << 'B' << endl;
        else cout << 'C' << endl;
    }

    return 0;
}