#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;

    cin >> s;
    int sz = (int)s.size();
    int i;
    int ok = 1;

    for (i = 0; i < sz; i++) {
        if (s[i] != 'A') break;
    }

    for (;i < sz; i++) {
        if (s[i] != 'B') break;
    }

    for (;i < sz; i++) {
        if (s[i] != 'C') break;
    }

    if (i != sz) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}