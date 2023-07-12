#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


//https://scrapbox.io/procon-kirokuyou/ARC150_B_-_Make_Divisible_(500)
int main()
{
    int t;

    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        if (a >= b) {
            cout << a- b << endl;
            continue;
        }
        if (b % a == 0) {
            cout << 0 << endl;
            continue;
        }

        ll ans = a - b%a;

        if (a < 1e6) {
            for (ll x = 0; x < a; x++) {
                if (b % (a+x) == 0) ans = min(ans, x);
                else ans = min(ans, x + (a+x) - b%(a+x));
            }
        } else {
            for (int i = 1; i <= b / a; i++) {
                ll x = ceil((double)(b - a*i) / i);
                ll y = (a + x) * i - b;
                ans = min(ans, x+y);
                // cout << x << " " << y << endl;
            }

            // for (int z = 1; z < 1e3; z++) {
            //     ll m = b - a * z;
            //     if (m > 0) {
            //         ll x = m / z;
            //         if (x * z < m) x++;
            //         ll y = x * z - m;
            //         ans = min(ans, x+y);
            //     } else {
            //         ans = min(ans, -m);
            //     }
            // }   
        }

        cout << ans << endl;
    }

    return 0;
}