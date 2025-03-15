#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n;
    cin >> s;
    n = (int)s.size();

    for (int i = 1; i <= n; i++) {
        if ('A' <= s.at(i-1) && s.at(i-1) <= 'Z') {
            cout << i << endl;
            break;
        }
    }

    return 0;
}