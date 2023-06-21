#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main()
{
    int n, m;
    
    while (1) {
        cin >> n >> m;

        if (n == 0 && m == 0) break;

        ll ans = 0;
        if (m <= 1) {
            ans = n * (n+1) - n;
            if (m == 1) ans -= 1;
        } else if (n == 0) {
            ans = m * (m+1) - m;
            ans *= -1;
            if (n == 1) ans += 1;
        } else {
            if (n == m) ans = 0;
            else if (n > m) {
                n -= m;
                m++;
                ll p = n / m;
                int rem = n % m;
                ll l = p * (p+1) + p;
                ans = l * p + (l - 2*p - 1) * rem;
                ans *= -1;
            }
            // int p = n / (m-1), rem;

            // if (p == 0) {
            //     n--;
            //     p = m / n;
            //     rem = m % n;
            //     ans = (ll)(p * (p+1) - p) * (n - rem);
            //     ans += (ll)((p+1) * (p+2) - (p+1)) * rem;
            //     ans++;
            //     ans *= -1;
            // } else {
            //     m--;
            //     rem = n % m;
            //     ans = (ll)(p * (p+1) - p - 1) * (m - rem);
            //     ans += (ll)((p+1) * (p+2) - (p+1) - 1) * rem;
            //     ans--;
            // }
        }

        cout << ans << endl; 
    }

    return 0;
}