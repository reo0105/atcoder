#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int x1, x2, x3;
        int ans = 0;
        cin >> x1 >> x2 >> x3;

        if (x1 % 2 != x2 % 2 || x2 % 2 != x3 % 2) {
            cout << -1 << endl;
            continue;
        }

        if (x2 > x3) swap(x2, x3);
        if (x1 > x2) swap(x1, x2);
        if (x2 > x3) swap(x2, x3);
        // cout << x1 << " " << x2 << " " << x3 << endl;

        int fir = x2 - x1;
        int sec = x3 - x2;

        ll diff = x3 - x2 + x2 - x1 + x3 - x1;

        // cout << fir << " " << sec << endl;

        if (fir > sec) {
            ans = sec / 2;
            x1 += sec;
            x3 -= sec;
            sec = x2 - x1;
            // cout << "sec " << sec << endl; 
            if (sec % 6 != 0) {
                cout << -1 << endl;
            } else {
                ans += sec / 3;
                cout << ans << endl;
            }
        } else {
            ans = fir / 2;
            x1 += fir;
            x3 -= fir;
            sec = x3 - x2;
            if (sec % 6 != 0) {
                cout << -1 << endl;
            } else {
                ans += sec / 3;
                cout << ans << endl;
            }
        }


    }
}