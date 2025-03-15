#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int cnt = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == t[cnt]+'a'-'A') cnt++;
    }

    if (cnt >= 3 || (cnt == 2 && t[2] == 'X')) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}