#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll h, w, k;
    vector<int> a(200005), b(200005);

    cin >> h >> w >> k;
    for (int i = 0; i < h; i++) cin >> a.at(i);
    for (int i = 0; i < w; i++) cin >> b.at(i);

    ll x = 0, y = 0;
    for (int i = 0; i < h; i++) {
        a.at(i) = ((k-1) * w - a.at(i)) % k;
        x += a.at(i);
    }
    for (int i = 0; i < w; i++) {
        b.at(i) = ((k-1) * h - b.at(i)) % k;
        y += b.at(i);
    }



    if (x%k != y%k) cout << -1 << endl;
    else cout << h*w*(k-1) - max(x, y) << endl;

    return 0;
}