#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;
    int n;
    set<char> s;

    cin >> str;
    n = (int)str.size();

    int flag0 = 1, flag1 = 0, flag2 = 0;
    for (int i = 0; i < n; i++) {
        if (s.count(str.at(i))) {
            flag0 = 0;
        } else {
            s.insert(str.at(i));
        }

        if ('A' <= str.at(i) && str.at(i) <= 'Z') flag1 = 1;
        if ('a' <= str.at(i) && str.at(i) <= 'z') flag2 = 1;
    }

    if (flag0 && flag1 && flag2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}