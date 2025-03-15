#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int rem = k;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (rem >= a) {
            rem -= a;
        } else {
            ans++;
            rem = k - a;
        }
    }

    if (rem != k) ans++;
    cout << ans << endl;

    return 0;
}