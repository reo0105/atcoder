#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int nim = 0;
    int maxi = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        nim ^= a[i];
        maxi = max(a[i], maxi);
    }

    if (nim != 0) {
        cout << -1 << endl;
        return 0;
    }

    int cnt = 0;
    while (maxi > 1) {
        maxi /= 2;
        cnt++;
    }
    
    int ans = 1;
    for (int i = 0; i < cnt; i++) ans *= 2;

    cout << ans << endl;

    return 0;
}

