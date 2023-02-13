#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int ans = 0, flag = 0;

    cin >> s;
    for (int i = 0; i < (int)s.size(); i++) {
        if (!flag && s.at(i) != '0') ans++;
        else if (!flag && s.at(i) == '0' ) {
            flag = 1;
            if (i == (int)s.size()-1) ans++;
        } else if (flag && s.at(i) == '0') {
            ans++;
            flag = 0;
        } else {
            flag = 0;
            ans += 2;
        }
    }

    cout << ans << endl;
    return 0;
}