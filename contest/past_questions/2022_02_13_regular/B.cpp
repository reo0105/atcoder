#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// int main()
// {
//     int n;
//     vector<int> s(300005);

//     cin >> n;
//     for (int i = 1; i <= n; i++) cin >> s.at(i);

//     ll b1, b2, b3;
//     ll c1 = -1000000000, c2 = -1000000000, c3 = -1000000000;
//     int i;

//     for (i = 1; i < n-2; i+=3) {
//         b1 = s.at(i+1) - s.at(i);
//         b2 = s.at(i+2) - s.at(i+1);
//         b3 = s.at(i+3) - s.at(i+2);

//         c1 = max(c1, b1*-1);
//         c2 = max(c2, b2*-1);
//         c3 = max(c3, b3*-1);
//         cout << c1 << " " << c2 << " " << c3 << endl;
//     }

    
//     if (i < n) {
//         b1 = s.at(i+1) - s.at(i);
//         cout << b1 << " ";
//         c1 = max(c1, b1*-1);
//     }

//     i++;

//     if (i < n) {
//         b2 = s.at(i+1) - s.at(i);
//         cout << b2 << " ";
//         c2 = max(c2, b2*-1);
//     }

//     i++;

//     if (i < n) {
//         b3 = s.at(i+1) - s.at(i);
//         cout << b3 << " ";
//         c3 = max(c3, b3*-1);
//     }

//     cout << endl;

//     if (c3 > s.at(1) - c1 - c2) {
//         cout  << "No" << endl;
//     } else {
//         cout << "Yes" << endl;
//         // cout << c1 << " " << c2 << endl;

//         ll x = (c1 < 0) ? 0 : c1;
//         ll y = (c2 < 0) ? 0 : c2;

//         cout << x << " " << y << " ";
//         for (int i = 1; i <= n; i++) {
//             ll z = s.at(i) - x - y;
//             cout << z << " ";
//             x = y; y = z;
//         }

//         cout << endl;
//     }

//     return 0;
// }


int main()
{
    int n;
    vector<int> s(300005);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s.at(i);

    int x = 0, y = 0;
    int b1, b2, b3;
    ll c1 = 0, c2 = 0, c3 = 1000000000;

    for (int i = 0; i < n; i++) {
        ll z = s.at(i) - x - y;
        // cout << z << endl;
    
        if (i % 3 == 1) {
            c1 = max(c1, -1*z); // aの下限
        } else if (i % 3 == 2) {
            c2 = max(c2, -1*z); // ｂの下限
        } else {
            c3 = min(c3, z); // a+bの上限
        }

        x = y; y = z;
    }

    // cout << c1 <<" " << c2 << " " << c3 <<endl;

    if (c1 + c2 > c3) cout << "No" << endl;
    else {
        cout << "Yes" << endl;
        int a0 = c1 < 0 ? 0 : c1;
        int b0 = c2 < 0 ? 0 : c2;

        cout << a0 << " " << b0 << " ";

        for (int i = 0; i < n; i++) {
            int z = s.at(i) - a0 - b0;
            cout << z << " ";
            a0 = b0; b0 = z;
        }
        cout << endl;
    }

    return 0;
}