#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    ll n;
    
    cin >> s;
    cin >> n;

    int k = 0;
    ll two = 1;
    ll ans = 0;

    int sz = (int)s.size();

    for (int i = 0; i < sz; i++) {
        if (s.at(i) == '1') ans += 1L<<(sz-1-i);
    }

    if (ans > n) {
        cout << -1 << endl;
        return 0;
    }

    two <<= (sz-1);
    for (int i = 0; i < sz; i++) {
        if (s.at(i) == '?') {
            if (ans + two <= n) ans += two;
        }
        two >>= 1;
    }

    cout << ans << endl;



    // while (n / two != 0) {
    //     k++;
    //     two *= 2;
    // }

    // ll lim = (1L<<sz) - 1;
    // vector<ll> t(65, 0);
    
    // if (n > lim) {
    //     for (int i = 0; i < sz; i++) {
    //         if(s.at(i) == '?') s.at(i) = '1';
    //     }
    //     // cout << stoll(s) << endl;
    // } else {
    //     for (int i = 0; i < sz-k; i++) {
    //         if (s.at(i) == '?') s.at(i) = '0';
    //     }

    //     ll two = 1;
    //     for (int i = 0; i < k; i++) {
    //         if (s.at(sz-1-i) == '?') t.at(sz-1-i) = two;
    //         two<<=1;
    //     }
    // }

    // ll ans = 0;
    // int flag = 0;

    // for (int i = sz-1; i >= 0; i--) {
    //     if (s.at(i) == '1' && ((ans + 1L<<i) <= n)) ans += 1L << (sz-1- i);
    //     else if (flag == 0 && (n >> i) & 1) {
    //         ans += t.at(i);
    //         if (t.at(i) == 0) flag = 1;
    //     } else if (flag) ans += t.at(i);
    //     cout << ans << endl;;
    // }
    // cout << endl;

    // if (ans <= n) cout << ans << endl;
    // else cout << -1 << endl;

    return 0;
}