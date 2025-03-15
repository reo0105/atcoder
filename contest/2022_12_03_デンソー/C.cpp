#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;

    cin >> s >> t;

    for (int i = 0; i < (int)t.size(); i++) {
        if (i == (int)s.size()) {
            cout << i+1 << endl;
            break;
        }

        if (s.at(i) != t.at(i)) {
            cout << i+1 << endl;
            break;
        }
    }


    return 0;
}