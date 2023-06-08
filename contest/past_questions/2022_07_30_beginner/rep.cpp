#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    ll ans;
    if (a <= b) {
        ans = n-a+1;
    } else {
        ll q = n / a;
        q--;
        ll rem = n % a;
        if (rem >= b) ans = q*b + b;
        else ans = q*b + rem + 1;
        // else ans = q*b + rem;
    }

    ans = max(ans, 0LL);

    cout << ans << endl;

    return 0;
}