#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    int k = sum / n;
    int rem = sum % n;

    sort(a.rbegin(), a.rend());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        if (i < rem) {
            ans += abs(a[i] - (k+1));
        } else {
            ans += abs(a[i] - k);
        }
    }

    cout << ans / 2 << endl;

    return 0;
}