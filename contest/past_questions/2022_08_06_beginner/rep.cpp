#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(200005, 0);
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<ll> sum(200005, 0);
    for (int i = 1; i <= n; i++) sum.at(i) = sum.at(i-1) + a.at(i);

    vector<ll> suml(200005, 2e18);
    vector<ll> sumr(200005, 2e18);

    suml.at(0) = 0;
    sumr.at(n+1) = 0;
    for (int i = 1; i <= n; i++) suml.at(i) = min(suml.at(i-1) + a.at(i), (ll)l*i);
    for (int i = n; i >= 0; i--) sumr.at(i) = min(sumr.at(i+1) + a.at(i), (ll)r*(n-i+1));

    // for (int i = 1; i <= n; i++) cout << suml.at(i) << " ";
    // cout << endl;
    // for (int i = 1; i <= n; i++) cout << sumr.at(i) << " ";
    // cout << endl;


    ll ans = sum.at(n);
    for (int i = 0; i <= n; i++) ans = min(ans, suml.at(i)+sumr.at(i+1));

    cout << ans << endl;

    return 0;
} 