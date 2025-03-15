#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    const int m = 1e8;
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    vector<ll> sum_a(n+1);
    for (int i = 1; i<= n; i++) sum_a[i] = sum_a[i-1] + a[i-1];

    ll ans = sum_a[n] * (n-1);
    // cout << ans << endl;

    for (int i = 0; i < n; i++) {
        int ai = a[i];
        int rem = m - ai; 
        int idx = a.end() - lower_bound(a.begin()+i+1, a.end(), rem);
        ans -= m * (ll)idx;
        // cout << idx << " " << ans << endl;
    }
    cout << ans << endl;


    return 0;
}