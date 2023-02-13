#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    int l = a-1, r = a+1;

    if (l == 0) l = 10;
    if (r == 11) r = 1;

    if (l == b || r == b) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}