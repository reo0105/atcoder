#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(200005);
//https://sen-comp.hatenablog.com/entry/2020/01/16/174230

vector<int> z_algorithm(string s)
{
    int c = 0, n = s.size();
    vector<int> z(n, 0);

    for (int i = 1; i < n; i++) {
        int l = i - c; //赤線の左点から現在の点までの距離

        if (i + z[l] < c + z[c]) { //cは赤線の左点、 iは今求めたい点、 だからこの式は　青線 < 赤線!
            z[i] = z[l]; //結果を再利用
        } else {
            int j = max(0, c+z[c]-i); // c+z[c]:赤線の右点, i:今求めたい点、だからこの式は赤線と青線が被ってないときに0、被ってたらその分がj

            while (i+j < n && s[j] == s[i+j]) j++; //先頭のj文字目以降と、求めたい点からのj文字以降と愚直に比較

            z[i] = j;

            c = i; //赤線は一番右にあるものを使う --> 含まれる可能性が高くなるからだよなたぶん
        }
    }

    z[0] = n;
    return z;
}

int main() {
    int n;
    cin >> n;
    string t;
    cin >> t;
    
    string a = t.substr(0, n);
    string b = t.substr(n);
    reverse(b.begin(), b.end());
    
    string x = a + b;
    vector<int> za_x = z_algorithm(x);
    za_x.push_back(0);
    
    string y = b + a;
    vector<int> za_y = z_algorithm(y);
    za_y.push_back(0);
    
    for (int i = 0; i <= n; i++) {
        if(za_x[2 * n - i] < i) continue;
        if(za_y[n + i] < n - i) continue;
        cout << t.substr(0, i) + t.substr(n + i) << endl;
        cout << i << endl;
        return 0;
    }
    
    cout << -1 << endl;
}