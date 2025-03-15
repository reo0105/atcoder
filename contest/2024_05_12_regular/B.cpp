#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    string s;
    cin >> n >> s;

    int m = 0;
    string ans;
    int pre = 0;
    for (int i = n-1; i >= 0; i--) {
        int c = s[i] - '0';
        if (pre == c) continue;
        if (c == 1) {
            for (int j = 0; j < i+1; j++) ans.push_back('A');
            m += i+1;
            pre = 1;
        } else {
            for (int j = 0; j < i+1; j++) ans.push_back('B');
            m += i+1;
            pre = 0;
        }
    }

    cout << m << endl;
    cout << ans << endl;
    // for (int i = m-1; i >= 0; i--) cout << ans[i];
    // cout << endl;

    return 0;
}