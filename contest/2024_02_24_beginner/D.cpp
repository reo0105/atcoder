#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    ll ans = 0;
    ll zero = 0;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];

        if (a[i] == 0) {
            ans += n-1;
            zero++;
        }
    }

    ans -= zero * (zero - 1) / 2;

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        if (a[i] == 0) continue;

        for (int j = 2; j*j <= a[i]; j++) {
            while ((a[i] % (j*j)) == 0) {
                a[i] /= j;
                a[i] /= j;
            }
        }

        mp[a[i]]++;
    }

    for (auto p : mp) {
        ll cnt = p.second;
        ans += cnt * (cnt-1) / 2;
    }

    cout << ans << endl;
 
    return 0;
}