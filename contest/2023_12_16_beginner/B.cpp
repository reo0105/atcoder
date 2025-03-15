#include <bits/stdc++.h>
using namespace std;

int main() 
{
    string s, t;
    cin >> s >> t;

    if (s[0] > s[1]) swap(s[0], s[1]);
    if (t[0] > t[1]) swap(t[0], t[1]);

    int x, y;

    if (s == "AB" || s == "BC" || s == "CD" || s == "DE" || s == "AE") x = 1;
    else  x = 2;
    if (t == "AB" || t == "BC" || t == "CD" || t == "DE" || t == "AE") y = 1;
    else y = 2;

    if (x == y) cout << "Yes" << endl;
    else cout << "No" << endl;
}