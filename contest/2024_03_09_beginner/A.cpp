#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    string ans;

    cin >> s;

    int i;
    for (i = 0; i < (int)s.size(); i++) {
        if (s[i] == '|') break;
        else ans.push_back(s[i]); 
    }

    for (i++; i < (int)s.size(); i++) {
        if (s[i] == '|') break;
    }

    for (i++; i < (int)s.size(); i++) {
        ans.push_back(s[i]);
    }

    cout << ans << endl;

    return 0;
}