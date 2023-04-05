#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 8;

    for (int i = n; i >= 1; i--) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s.at(j) == '*') {
                char c = 'a' + j;
                cout << c << i << endl;
                return 0;
            }
        }
    }

    return 0;
} 