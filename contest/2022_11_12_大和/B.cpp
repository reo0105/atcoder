#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, flag = true;
    set<string> s;
    string t;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> t;
        s.insert(t);
        switch (t.at(0)) {
            case 'H':
            case 'D':
            case 'C':
            case 'S': break;
            default: flag = false;
        }

        switch (t.at(1)) {
            case 'A':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8': 
            case '9':
            case 'T':
            case 'J':
            case 'Q':
            case 'K': break;
            default: flag = false;
        }
    }

    if ((int)s.size() != n) {
        flag =false;
    }

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}