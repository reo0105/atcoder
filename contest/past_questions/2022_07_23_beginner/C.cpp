#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<string, int> mp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (mp[s] != 0) {
            cout << s << '(' << mp[s] << ')' << endl;
            mp[s]++;
        } else {
            mp[s] = 1;
            cout << s << endl;
        }
    }

    return 0;
}