#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int vol = 3;
ll prime[vol] = {1000000007, 1000000009, 1000000033};
// ll prime[5] = {1000000007, 1000000009, 1000000021, 1000000033, 1000000087};


int main()
{
    int n;
    cin >> n;

    vector<string> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<vector<ll>> as(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < vol; j++) {
            ll t = 0;
            for (char c : a[i]) {
                t = (t*10 + c-'0') % prime[j];
            }
            as[i].push_back(t);
        }
    }

    map<vector<ll>, int> cnt;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            vector<ll> multi;
            for (int k = 0; k < vol; k++) {
                multi.push_back(as[i][k] * as[j][k] % prime[k]);
            }
            cnt[multi]++;
        }
    }

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        ans += cnt[as[i]];
    }

    cout << ans << endl;
}