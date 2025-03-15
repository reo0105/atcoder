#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int n;

    cin >> s;
    n = (int)s.size();

    if (n == 1) for (int i = 0; i < 6; i++) cout << s;
    else if (n == 2) for (int i = 0; i < 3; i++) cout << s;
    else for (int i = 0; i < 2; i++) cout << s;
    cout << endl;

    return 0;
}