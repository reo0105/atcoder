#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s, t;

    cin >> n >> s >> t;

    int flag = 1;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == t.at(i)) continue;
        if (s.at(i) == 'l' && t.at(i) == '1') continue;
        if (s.at(i) == '1' && t.at(i) == 'l') continue;
        if (s.at(i) == 'o' && t.at(i) == '0') continue;
        if (s.at(i) == '0' && t.at(i) == 'o') continue;
        flag = 0;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}