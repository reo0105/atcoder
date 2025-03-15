#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> s = {"#"};

    for (int i = 0; i < n; i++) {
        int sz = (int)s.size();
        int sz3 = sz * 3;
        vector<string> t(sz3, string(sz3, '.'));

        for (int j = 0; j < sz3; j++) {
            for (int k = 0; k < sz3; k++) {
                t[j][k] = s[j%sz][k%sz];
            }
        }

        for (int j = 0; j < sz; j++) {
            for (int k = 0; k < sz; k++) {
                t[j+sz][k+sz] = '.';
            }
        }

        swap(s, t);
    }

    for (string ans : s) cout << ans << endl;

    return 0;
}