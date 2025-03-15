#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> q(n), a(n), b(n);

    for (int i = 0; i < n; i++) cin >> q[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    int ans = 0;
    int maxi = 1e9;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;
        maxi = min(maxi, q[i] / a[i]);
    }

    for (int i = 0; i < n; i++) {
        q[i] -= a[i] * maxi;
    }

    ans = maxi;
    for (int i = 0; i <= maxi; i++) {

        int tmp = 1e9;
        for (int j = 0; j < n; j++) {
            if (b[j] == 0) continue;
            tmp = min(tmp, q[j] / b[j]);
        }
        ans = max(ans, maxi-i+tmp);
        
        for (int j = 0; j < n; j++) q[j] += a[j];
    }

    cout << ans << endl;

    return 0;
}