#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    string x;

    cout << 2*n << endl;

    if (n % 4 != 0) {
        x.push_back('0' + n%4);
        n -= n%4;
    }

    for (int i = 0; i < n/4; i++) {
        x.push_back('4');
    }

    cout << x << endl;

    return 0;
}