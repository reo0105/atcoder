#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, t;
    int count = 0, flag = 0;

    cin >> s >> t;

    for (int i = 0; i < (int)s.size(); i++) {
        for (int j = 0; j < (int)t.size(); j++) {
            if (i+j < (int)s.size() && s.at(i+j) == t.at(j)) count++;
        }
        if (count == (int)t.size()) flag = 1;
        else count = 0;
    }

 
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}