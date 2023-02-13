#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n;

    cin >> s;
    n = (int)s.size();

    for (int i = n-1; i > 0; i--) {
        s.at(i) = s.at(i-1);
    }
    s.at(0) = '0';

    cout << s << endl;
}