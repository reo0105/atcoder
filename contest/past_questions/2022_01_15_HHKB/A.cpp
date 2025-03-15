#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, x;
    int ans;

    cin >> x;

    a = x / 100;
    c = x % 10;
    b = ((x-c) / 10) % 10;

    ans = 100*a+10*b+c + 100 * b + 10 * c + a + 100 * c + 10 * a + b;

    cout << ans << endl;

    return 0;
}