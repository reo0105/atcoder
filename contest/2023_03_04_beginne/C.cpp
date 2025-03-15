#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    ll ans = 0;

    for (int ab = 1; ab <= n-1; ab++) {
        ll t = 0;
        for (int i = 1; i*i <= ab; i++) {
            if (ab%i == 0 && ab/i == i) t++;
            else if (ab%i == 0) t += 2;
        }

        ll s = 0;
        for (int i = 1; i*i <= n-ab; i++) {
           if ((n-ab)%i == 0 && (n-ab)/i == i) s++;
            else if ((n-ab)%i == 0) s += 2;
        }

        ans += s*t;
    }

    cout << ans << endl;

    return 0;
}