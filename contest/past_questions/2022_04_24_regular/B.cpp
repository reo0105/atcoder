#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll n, a, b, x, y, z;
        cin >> n >> a >> b >> x >> y >> z;

        /* xとコスト比較 */
        y = min(y, a*x);
        z = min(z, b*x);

        // cout << y << " " << z << endl;
        /* 単位量あたりがaの方が小さくなるようにする */
        if ((double)y/a > (double)z/b) {
            swap(y,z);
            swap(a,b);
            // cout << "swap" << endl;
        }

        /*この時Bは高々A-1回以下に抑えられる*/
        ll ans = 1e18;
        if (n/a >= a) {
            // cout << "root 1" << endl;
            for (int i = 0; i <= a-1; i++) {
                ll c = z*i;
                // cout << i << " " << c << endl;
                ll cnta = (n - b*i) / a;
                if (cnta < 0) break;
                c += y * cnta;
                // if (n - cnta*a - i*b < 0) cout << i << " minus" << endl;
                if (n - cnta*a - i*b < 0) break;
                c += (n - cnta*a - i*b)*x;
                ans = min(ans, c);
            }
            // if (a == 0) {
            //     ll c = 0;
            //     int cnta = n / a;
            //     c += y * cnta;
            //     c += (n - cnta);
            //     ans = min(ans, c);
            // }
        } else {
            for (int i = 0; i <= n/a; i++) {
                ll c = y*i;
                ll cntb = (n - a*i) / b;
                if (cntb < 0) break;
                c += z * cntb;
                if (n - cntb*b - i*a < 0) break;
                c += (n - cntb*b - i*a)*x;
                ans = min(ans, c);
            }
            // if (n/a == 0) {
            //     ll c = 0;
            //     int cntb = n / b;
            //     c += z * cntb;
            //     c += (n - cntb);
            //     ans = min(ans, c);
            // }
        }
        cout << ans << endl;
    }


    return 0;
}