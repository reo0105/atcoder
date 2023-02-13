#include <bits/stdc++.h>
using namespace std;

int main()
{
    set<int> s;
    string str;

    for (int i = 0; i < 10; i++) s.insert(i);

    cin >> str;
    for (int i = 0; i < 9; i++) {
        s.erase(str.at(i) - '0');
    }

    cout << *begin(s) << endl;

    return 0;
}