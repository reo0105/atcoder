#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int ans = -1;

    cin >> s;

    for (int i = 0; i < s.size(); i++) {
        if (s.at(i) == 'a') ans = i;
    }

    if (ans != -1) {
        cout << ans+1 << endl;
    } else {
        cout << -1 << endl;
    }

    return 0;
}