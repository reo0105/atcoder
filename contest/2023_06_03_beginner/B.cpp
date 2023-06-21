#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = (int)s.size();

    if (n <= 3) cout << s << endl;
    else {
        for (int i = 0; i < 3; i++) cout << s.at(i);
        for (int i = 3; i < n; i++) cout << 0;
    }

    return 0;
}