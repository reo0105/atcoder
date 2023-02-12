#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> s;

    n = (int)s.size();
    for (int i = 0; i < n; i++) {
        if (s.at(i) == '0') s.at(i) = '1';
        else s.at(i) = '0';
    }

    cout << s << endl;

    return 0;
}