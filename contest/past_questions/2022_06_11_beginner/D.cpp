#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, q;
    vector<int> a;

    cin >> n >> q;
    for (int i = 0; i < n; i++) { int t; cin >> t; a.push_back(t); }

    sort(a.begin(), a.end());

    vector<ll> sum(200005, 0);
    for (int i = 1; i <= n; i++) {
        sum.at(i) = sum.at(i-1) + a.at(i-1);
    }

    ll ans = 0;
    for (int i = 0; i < q; i++) {
        ll x;
        cin >> x;
        int k = upper_bound(a.begin(), a.end(), x) - a.begin();
        // cout << k << endl;
        ans = k*x - sum.at(k);
        ans += sum.at(n) - sum.at(k) - (n-k) * x;
        cout << ans << endl;
    }

    return 0;
}