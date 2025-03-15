#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b;
    cin >> a >> b;

    ll ans = a / b;
    if (a % b != 0) ans++;

    cout << ans << endl;
    
    return 0;
}