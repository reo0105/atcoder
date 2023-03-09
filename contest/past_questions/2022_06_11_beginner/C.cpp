#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll x, a, d, n;
    cin >> x >> a >> d >> n;


    // if (d != 0 && (x == a || ((x - a) % d) == 0)) cout << (x-a) << endl;
    // else {
        if (d == 0) { 
            cout << abs(x-a) << endl;
            return 0;
        }
        if (d < 0) {
            a = a+(n-1)*d;
            d = -d;
        }
        
        ll ans = 1L<<61;
        ll near = (x-a) / d;
        if (near < 0) near = 0;
        else if (near >= n) near = n-1;
        ll t = a + d*near;
        ans = min(ans, abs(x-t));

        near++;
        if (near < 0) near = 0;
        else if (near >= n) near = n-1;
        t = a + d*near;
        ans = min(ans, abs(x-t));

        near -= 2;
        if (near < 0) near = 0;
        else if (near >= n) near = n-1;
        t = a + d*near;
        ans = min(ans, abs(x-t));
        cout << ans << endl;
    // }



    return 0;
}