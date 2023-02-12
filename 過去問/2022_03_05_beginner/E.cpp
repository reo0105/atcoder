#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n;
        string s;
        cin >> n >> s;

        int loop = (n+1) / 2;
        ll alpha = 1;
        
        string s_inv(s.rbegin(), s.rend());
        string x = s.substr(0, loop) + s_inv.substr(loop);

        // cout << x << endl;

        ll ans = 0;
        if (x <= s) ans++;

        for (int i = loop-1; i >= 0; i--) {
            ans += (s.at(i)-'A') * alpha;
            alpha *= 26;
            ans %= MOD;
            alpha %= MOD;
        }

        cout << ans << endl;
    }

    return 0;
}