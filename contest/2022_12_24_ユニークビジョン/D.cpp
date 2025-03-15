#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int flag = 1, exi = 0;
    set<char> s;

    cin >> str;

    for (int i = 0; i < (int)str.size(); i++) {
        if (str.at(i) == '(') {
            ;
        } else if (str.at(i) == ')') {
            s.clear();
            exi = 1;
        } else {
            if (s.count(str.at(i))) {
                flag = 0;
                break;
            }
            s.insert(str.at(i));
        }
    }

    if (flag && exi) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}