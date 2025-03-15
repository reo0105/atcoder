#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int h, w, k;
    vector<int> a(200005), b(200005);

    cin >> h >> w >> k;
    for (int i = 0; i < h; i++) cin >> a.at(i);
    for (int i = 0; i < w; i++) cin >> b.at(i);

    ll suma = 0, sumb = 0;

    for (int i = 0; i < h; i++) suma += a.at(i);
    for (int i = 0; i < w; i++) sumb += b.at(i);

    if (suma % k != sumb % k) {
        cout << -1 << endl;
    } else {
        ll maxi = (ll)(k-1) * h;

        ll ans = 0;
        for (int i = 0; i < w; i++) {
            ans += (ll)(maxi - b.at(i)) / k * k + b.at(i);
        }

        ll t = 0;
        maxi = (ll)(k-1) * w;
        for (int i = 0; i < h; i++) {
            t += (ll)(maxi - a.at(i)) / k * k + a.at(i);
        }

        ans = min(t, ans);
        cout << ans << endl;
    }
    
    return 0;
}