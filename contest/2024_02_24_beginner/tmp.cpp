#include  <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    int zero = n-1;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (a[i] == 0) {
            ans += zero;
            zero--;
        }
    }

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int now = a[i];

        for (int i = 2; i*i <= now; i++) {
            while ((now % (i*i)) == 0) {
                now /= (i*i);
            }
        }

        mp[now]++;
    }


    for (auto [k, v] : mp) {
        if (k == 0) continue;
        ans += (ll)v * (v-1) / 2;
    }

    cout << ans << endl;

    return 0;
}