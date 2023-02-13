#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    ll ans = 0;
    int num = (int)s.size();

    for (int i = 0; i <= num-1; i++) {
        ll t = 1;
        for (int j = 0; j < i; j++) {
            t *= 26;
        }
        ans += t;
    }

    for (auto c : s) {
        ll t = 1;
        for (int i = 0; i < num-1; i++) {
            t *= 26;
        }
        // cout << t << endl;
        t *= c-'A';
        // cout << t << endl;
        ans += t;
        num--;
    }

    cout << ans << endl;

    return 0;
}