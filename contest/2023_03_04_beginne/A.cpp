#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = (int)s.size();

    for (int i = 0; i < n; i++) {
        s.at(i) -= 32;
        cout << s.at(i);
    }

    return 0;
}