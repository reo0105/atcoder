#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, x;
    vector<int> a(200005), b(200005);

    cin >> n >> x;
    for (int i = 1; i <= n; i++) cin >> a.at(i) >> b.at(i);

    vector<ll> sum(200005, 0);

    for (int i = 1; i <= n; i++) {
        sum.at(i) = sum.at(i-1) + a.at(i) + b.at(i);
    }


    ll ans = sum.at(1) + (ll)(x - 1) * b.at(1);
    for (int i = 2; i <= n; i++) {
        if (i > x) break;
        ans = min(ans, sum.at(i) + (ll)(x - i) * b.at(i));
    }

    cout << ans << endl;

    return 0;
}