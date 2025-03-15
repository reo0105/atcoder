#include <bits/stdc++.h>

using namespace std;

int main()
{
    int x, y;
    cin >> x >> y;

    if (x > y && x - y <= 3) cout << "Yes" << endl;
    else if (x < y && y - x <= 2) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}