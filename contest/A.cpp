#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, cnt = 0, flag = 0;
        string s;
        cin >> n >> s;
        for (int i = 0 ; i < n; i++) {
            if (s.at(i) == '1') cnt++;
            if (i > 0 && s.at(i) == '1' && s.at(i-1) == '1') flag = 1;
        }

        if (cnt % 2 == 1) {
            cout << -1 << endl;
        } else {
            if (n == 3 && flag) cout << -1 << endl;
            else if (s == "0110") cout << 3 << endl;
            else if (cnt == 2 && flag) cout << 2 << endl;
            else cout << cnt / 2 << endl;
        }
    }
    return 0;
}