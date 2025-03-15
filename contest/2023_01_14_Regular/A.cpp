#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int n, i, s1;
//     int lim, cnt = 0;

//     cin >> n;

//     s1 = n / 100000 + 1;
//     lim = (s1 + 1) * 110000000;
//     cnt = (s1 -1) * 100000;
//     s1 *= 110000000;


//     // cout << s1 <<  " " << lim << " " << cnt << endl;

//     for (i = s1; i <= lim; i++) {
//         int s5, s6, s7, s8, s9;
//         s9 = i % 10;
//         s8 = ((i % 100) - s9) / 10;
//         s7 = ((i % 1000) - s9 - s8*10) / 100;
//         s6 = ((i % 10000) - s9 - s8*10 - s7*100) / 1000;
//         s5 = ((i % 100000) - s9 - s8*10 - s7*100 - s6*1000) /10000;
//         if (s9 == s7 && s5 == s6) cnt++;

//         if (cnt == n) break;
//     }

//     if (n == 900000) cout << 999999999 << endl;
//     else cout << i << endl;

//     return 0;
// }

int main()
{
    int n;
    int a = 1, b = 0, c = 0, d = 0, e = 0, f = -1;

    cin >> n;

    for (int i = 0; i < n; i++) {
        f++;
        if (f == 10) {
            e++;
            f = 0;
        }
        if (e == 10) {
            d++;
            e = 0;
        }
        if (d == 10) {
            c++;
            d = 0;
        }
        if (c == 10) {
            b++;
            c = 0;
        }
        if (b == 10) {
            a++;
            b = 0;
        }
    }

    int ans = a*110000000+b*1000000+c*100000+d*11000+e*101+f*10;

    cout << ans << endl;

}