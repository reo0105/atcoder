#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;


int main()
{
    int n, x;
    cin >> n >> x;

    vector<int> u(n), d(n);
    for (int i = 0; i < n; i++) cin >> u[i] >> d[i];

    int mini = 2e9+5;
    for (int i = 0; i < n; i++) mini = min(mini, u[i] + d[i]);

    vector<int> diff(n);
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += u[i] + d[i];
    }


    ll l = 0, r = 2e18+1;
    while (r - l > 1)
    {
        ll mid = (l + r) / 2;
        ll ul = 0, ur = mid;
        bool ok = true;
        for (int i = 0; i < n-1; i++) {
            ll nl = mid - u[i], nr = d[i];
            nl = max(nl, 0LL);
            nr = min(nr, mid);

            nl = max(nl, ul-x);
            nr = min(nr, ur+x);

            if (nr < nl) ok = false;
            ul = nl, ur = nr;
        }

        if (ok) l = mid;
        else r = mid;
    }

    cout << l << " " << r << endl;
    cout << ans - (ll)l*n << endl;

    return 0;
}