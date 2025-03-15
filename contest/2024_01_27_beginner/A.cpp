#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int ok = 1;

    for (int i = 0; i < (int)s.size(); i++) {
        if (i == 0 && ('A' > s[i] || s[i] > 'Z')) ok = 0;
        if (i != 0 && ('a' > s[i] || s[i] > 'z')) ok = 0;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}