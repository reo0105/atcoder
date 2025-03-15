#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = (int)s.size();
    int ok = 1;

    if (s[0] != '<') ok = 0;

    for (int i = 1; i < n-1; i++) {
        if (s[i] != '=') ok = 0;
    }

    if (s[n-1] != '>') ok = 0;

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;

}