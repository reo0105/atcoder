#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    char ans = ' ';
    map<char, int> m;
    cin >> s;

    for (int i = 0; i < 3; i++) {
        m[s.at(i)]++;
    }

    for (auto p : m) {
        if (p.second == 1) ans = p.first;
    }

    if (ans == ' ') cout << -1 << endl;
    else cout << ans << endl;



    return 0;
}