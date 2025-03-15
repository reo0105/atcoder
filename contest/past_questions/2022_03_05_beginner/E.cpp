// #include <bits/stdc++.h>
// using namespace std;
// typedef long long ll;
// #define MOD 998244353

// int main()
// {
//     int t;
//     cin >> t;

//     for (int i = 0; i < t; i++) {
//         int n;
//         string s;
//         cin >> n >> s;

//         int loop = (n+1) / 2;
//         ll alpha = 1;
        
//         string s_inv(s.rbegin(), s.rend());
//         string x = s.substr(0, loop) + s_inv.substr(loop);

//         // cout << x << endl;

//         ll ans = 0;
//         if (x <= s) ans++;

//         for (int i = loop-1; i >= 0; i--) {
//             ans += (s.at(i)-'A') * alpha;
//             alpha *= 26;
//             ans %= MOD;
//             alpha %= MOD;
//         }

//         cout << ans << endl;
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

ll modpow(ll a, ll y)
{
    ll ret = 1;
    while (y > 0) {
        if (y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        string s;
        cin >> n >> s;

        int loop = (n+1) / 2;
        string invs(s.rbegin(), s.rend());
        string x = s.substr(0, loop) + invs.substr(loop);

        ll ans = 0;
        if (x <= s) ans++;

        ll alpha = 1;
        ll inv_alpha = modpow(26, MOD-2);
        
        for (int i = 1; i < loop; i++) { alpha *= 26; alpha %= MOD; } 
        for (int i = 0; i < loop; i++) {
            ans += (s.at(i) - 'A') * alpha;
            ans %= MOD;
            alpha *= inv_alpha;
            alpha %= MOD;
        }

        cout << ans << endl;
    }

    return 0;
}