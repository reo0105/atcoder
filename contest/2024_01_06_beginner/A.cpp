#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = (int)s.size();

    s[n-1] = '4';
    cout << s << endl;
}