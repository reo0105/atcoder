#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    if (n % 10 >= 3 && n % 10 <= 7) n = n / 10 * 10 + 5;
    else if (n % 10 < 3) n = n / 10 * 10;
    else n = n / 10 * 10 + 10;

    cout << n << endl;

    return 0;
}