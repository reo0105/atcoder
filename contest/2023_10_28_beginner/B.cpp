#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;

    while (1) {
        int x = n / 100;
        int y = (n % 100 - n % 10) / 10;
        int z = n % 10;

        if (x * y == z) break;
        else n++;
    }

    cout << n << endl;

    return 0;
}