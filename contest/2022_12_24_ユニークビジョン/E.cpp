#include <bits/stdc++.h>
using namespace std;

// int main()
// {
//     int h, w, ans = 0;
//     vector<vector<int>> a(1002, vector<int>(1002, -1));
//     vector<int> x_axis = {0, -1, 0, 1}; //gyou
//     vector<int> y_axis = {1, 0, -1, 0}; // retu
//     set<int> s;

//     cin >> h >> w;

//     for (int i = 0; i < h; i++) {
//         for (int j = 0; j < w; j++) {
//             cin >> a.at(i).at(j);
//         }
//     }

//     for (int i = 0; i < h; i++) {
//         for (int j = 0; j < w; j++) {
//             int alone = 1;
//             for (int k = 0; k < 4; k++) {
//                 if (0 <= i+x_axis.at(k) && i+x_axis.at(k) < h && 0 <= j+y_axis.at(k) && j+y_axis.at(k) < w) {
//                     if (a.at(i+x_axis.at(k)).at(j+y_axis.at(k)) == a.at(i).at(j)) alone = 0;
//                 }
//             }
//             if (alone) {
//                 s.insert(i);
//                 // cout << i << " " << j << endl;
//             }
//         }
//     }

//     // cout << s.size() << endl;

//     int ok = 1;

//     for (int i = 0; i < h; i++) {
//         if (s.count(i)) {
//             if ((a.at(i).at(1) != a.at(i).at(0) && i+1 < h && a.at(i+1).at(0) == a.at(i).at(0))) {
//                 if (a.at(i).at(w-2) != a.at(i).at(w-1) && i+1 < h && a.at(i+1).at(w-1) != a.at(i).at(w-1)) {
//                     ok = 0;
//                 }
//             }
//         }

//         if (num >= 1 && row.at(num-1) == h-1) {
//             if ((a.at(h-1).at(1) != a.at(h-1).at(0) && a.at(h-2).at(0) == a.at(h-1).at(0))) {
//                 if (a.at(h-1).at(w-2) != a.at(h-1).at(w-1) && a.at(h-2).at(w-1) != a.at(h-1).at(w-1)) {
//                     ok = 0;
//                 }
//             }
//         }
//     }

//     int num = (int)s.size();
//     vector<int> row(1002);
//     for (int i = 0; i < num; i++) {
//         row.at(i) = *begin(s);
//         s.erase(row.at(i));
//         // cout << row.at(i) << endl;
//     }

//     for (int i = 0; i < num; i++) {
//         if (i+1 < num && i+2 < num && row.at(i) == row.at(i+1)-1 && row.at(i+1) == row.at(i+2)-1) {
//             ans++;
//             i+=2;
//         } else if (i+1 < num && (row.at(i) == row.at(i+1)-1 || row.at(i) == row.at(i+1)-2)) {
//             ans++;
//             i+=1;
//         } else {
//             ans++;
//         }
//     }


//     if (ok) cout << ans << endl;
//     else cout << -1 << endl;

//     return 0;
// }

typedef long long ll;
#define INF 1L<<29

int main()
{
    int h, w;
    vector dp(1002, vector<vector<int>>(2, vector<int>(2, INF)));
    vector a(1002, vector<int>(1002, -1));

    cin >> h >> w;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a.at(i).at(j);
        }
    }

    dp.at(0).at(0).at(0) = 0;
    dp.at(0).at(0).at(1) = 1;
    for (int i = 1; i < h; i++) {
        for (int j = 0; j < 2; j++) { // 2つ前
            for (int k = 0; k < 2; k++) { // 1つ前
                for (int l = 0; l < 2; l++) { // now
                    vector<int> x(1002, -1);
                    if (i != 1) x = a.at(i-2);
                    if (j) for (int m = 0; m < w; m++) x[m] ^= 1;
                    vector<int> y = a.at(i-1);
                    if (k) for (int m = 0; m < w; m++) y[m] ^= 1;
                    vector<int> z = a.at(i);
                    if (l) for (int m = 0; m < w; m++) z[m] ^= 1;
                    bool ok = true;
                    for (int m = 0; m < w; m++) {
                        if (x.at(m) != y.at(m) && y.at(m) != z.at(m) && (m == 0 || y.at(m) != y.at(m-1)) && (m == w-1 || y.at(m) != y.at(m+1))) ok = false;
                    }
                    if (i==h-1) {
                        for (int m = 0; m < w; m++) {
                            if (z.at(m) != y.at(m) && (m == 0 || z.at(m) != z.at(m-1)) && (m==w-1 || z.at(m) != z.at(m+1))) ok = false;
                        }
                    }
                    if (ok) dp.at(i).at(k).at(l) = min(dp.at(i).at(k).at(l), dp.at(i-1).at(j).at(k)+l);
                }
            }
        }
    }

    int ans = INF;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++) {
            ans = min(ans, dp.at(h-1).at(i).at(j));
        }
    }

    if (ans == INF) ans = -1;
    cout << ans << endl;

    return 0;
}