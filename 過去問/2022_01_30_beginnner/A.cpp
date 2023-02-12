#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    ll t = 1;

    for (int i = 0; i < 31; i++) {
        t *= 2;
    }

    cin >> n;

    if (-1*t <= n && n < t) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}