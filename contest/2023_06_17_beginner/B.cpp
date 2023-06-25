#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;

int main()
{
    ll ans = 0;
    ll two = 1;

    for (int i = 0; i < 64; i++) {
        int a;
        cin >> a;
        ans += a * two;
        two <<= 1;
    }

    cout << ans << endl;

    return 0;
}