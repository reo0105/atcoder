#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    map<int, int> mp;

    for (int i = 0; i < (int)s.size(); i++) {
        mp[s[i] - 'a']++;
    }

    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
        if (maxi < mp[i]) {
            maxi = mp[i];
            ans = i;
        }
    }

    cout << (char)('a' + ans) << endl;

    return 0;
}