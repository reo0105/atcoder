#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll x;
    cin >> x;

    // if (x < 0 && x % 10 != 0) x -= 10;

    cout << x / 10 - (x % 10 < 0) << endl;

    return 0;
}