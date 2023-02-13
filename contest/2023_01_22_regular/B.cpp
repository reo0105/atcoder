#include <bits/stdc++.h>
using namespace std;

// vector<int> z_algorithm(string s)
// {
//     int c = 0, n = s.size();
//     vector<int> z(n, 0);

//     for (int i = 1; i < n; i++) {
//         int l = i - c; //赤線の左点から現在の点までの距離

//         if (i + z[l] < c + z[c]) { //cは赤線の左点、 iは今求めたい点、 だからこの式は　青線 < 赤線!
//             z[i] = z[l]; //結果を再利用
//         } else {
//             int j = max(0, c+z[c]-i); // c+z[c]:赤線の右点, i:今求めたい点、だからこの式は赤線と青線が被ってないときに0、被ってたらその分がj

//             while (i+j < n && s[j] == s[i+j]) j++; //先頭のj文字目以降と、求めたい点からのj文字以降と愚直に比較

//             z[i] = j;

//             c = i; //赤線は一番右にあるものを使う --> 含まれる可能性が高くなるからだよなたぶん
//         }
//     }

//     z[0] = n;
//     return z;
// }

int main()
{
    int n;
    string s, t;
    multiset<char> x, y;

    cin >> n >> s >> t;

    for (int i = 0; i < n; i++) {
        x.insert(s.at(i));
        y.insert(t.at(i));
    }

    if (x != y) {
        cout << -1 << endl;
    } else {
        int cnt = 0, j = n-1;
        for (int i = n-1; i >= 0; i--) {
            char target = s.at(i);
            for (; j >= 0; j--) {
                if (t.at(j) == target) {
                    cnt++;
                    j--;
                    break;
                }
            }

            if (j == 0 || j == -1) break;
        }

        cout << n - cnt << endl;
    }

    return 0;
}