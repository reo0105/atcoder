#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n/3; i++) {
        cout << "oox";
    }

    if (n % 3 == 1) cout << "o" << endl;
    else if (n % 3 == 2) cout << "oo" << endl;
    else cout << endl;

    return 0;
}