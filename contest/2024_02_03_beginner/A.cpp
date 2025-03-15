#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    string ans;

    int cnt = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '.') cnt = i+1;
    }

    for (int i = cnt; i < (int)s.size(); i++) {
        cout << s[i];
    }
    cout << endl;

    return 0;
}