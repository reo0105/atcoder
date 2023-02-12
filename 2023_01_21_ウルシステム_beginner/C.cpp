#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, a, b;
    string s;
    // vector<int> cnt(26, 0);

    cin >> n >> a >> b;
    cin >> s;

    // for (int i = 0; i < n; i++) [
        // cnt.at(s.at(i)-'a')++;
    // }

    int maxi = 0, match = 0;
    int top = 0, end = n-1;
    int index = 0;

    ll ans = 1L<<58, tmp;

    for (top = 0; top < n; top++) {
        tmp = top * a;
        if (top != 0) end = top-1;
        for (int i = 0; i < n/2; i++) {
            // if (top == 0) {
            //     cout << s.at((top+i)%n) << " " << s.at((end-i+n)%n) << endl;
            // }
            if (s.at((top+i)%n) == s.at((end-i+n)%n)) {
                match++;
            }
        }

        tmp += ((n/2) - match) * b;
        if (tmp < ans) ans = tmp;
        match = 0;
    }

    cout << ans << endl;

    return 0;
}