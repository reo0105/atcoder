#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, k;
    ll ans = 0;
    int same = 0;
    cin >> n >> k;

    string s = to_string(k);
    string t(s);
    reverse(t.begin(), t.end());

    if (s > t) {
        cout << 0 << endl;
        return 0;
    }

    if (s == t) same = 1;

    s.push_back('0');

    while (n >= k) {
        ans++;
        if (ans%2 == 1) { k = stoll(t); t.push_back('0'); }
        else { k = stoll(s); s.push_back('0'); }
        // cout << k << " " << s << " " << t << endl;
    }

    if (same) ans /= 2;

    cout << ans << endl;

    return 0;
}