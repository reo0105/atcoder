#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1L<<60

ll f(ll a, ll b)
{
    return a*a*a+a*a*b+a*b*b+b*b*b;
}

int main()
{
    ll n;
    

    cin >> n;

    ll ans = INF;
    for (int a = 0; a <= 1000000; a++) {
        int l = -1, r = 1000000, mid;

        while (r - l > 1) {
            mid = (r+l) / 2;
            if (f(a, mid) >= n) r = mid;
            else l = mid;
        }

        ans = min(ans, f(a, r));
    }

    cout << ans << endl;

    return 0;
}