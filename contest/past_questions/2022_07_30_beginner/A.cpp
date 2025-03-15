#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    if (s == "BA") cout << "No" << endl;
    else if (s.at(0) == 'B' || s.at(n-1) == 'A') cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}