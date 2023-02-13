#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, a, b;
    ll ans;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        ans = a + b;
        cout << ans << endl;
    }

    return 0;
}