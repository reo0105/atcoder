#include <bits/stdc++.h>
using namespace std;

int main()
{
    int k;
    char x = 'A';
    cin >> k;
    for (int i = 0; i < k; i++) {
        if (i != 0) x += 1;
        cout << x;
    }

    cout << endl;

    return 0;
}