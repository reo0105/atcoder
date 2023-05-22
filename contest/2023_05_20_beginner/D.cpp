#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    ll d;
    vector<ll> a(200005), b;

    cin >> n >> m >> d;
    for (int i = 0; i < n; i++) cin >> a.at(i);
    for (int i = 0; i < n; i++) {
        ll t;
        cin >> t;
        b.push_back(t);
    }

    sort(b.begin(), b.end());

    ll ans = -1;
    for (int i = 0; i < n; i++) {
        ll sel = a.at(i);

        ll maxi = upper_bound(b.begin(), b.end(), sel+d) - b.begin();

        if (maxi == 0) continue;
        // cout << sel << " " << maxi << endl;
        maxi--;

        if (abs(sel-b.at(maxi)) <= d) {
            // cout << sel << " " << maxi << endl;
            ans = max(ans, sel + b.at(maxi));
        }
    }

    cout << ans << endl;

    return 0;
}