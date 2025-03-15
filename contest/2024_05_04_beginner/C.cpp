#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i] >> b[i];

    vector<ll> sum_a(n+1);
    for (int i = 0; i < n; i++) sum_a[i+1] = sum_a[i] + a[i];

    ll ans = 0;
    ll t = sum_a[n];
    for (int i = 0; i < n; i++) {
        ans = max(ans, t-a[i]+b[i]);
    }

    cout << ans << endl;

    return 0;
}