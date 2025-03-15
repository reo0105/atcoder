#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x, ll y, ll u, ll v)
{
    return (x-u) * (x-u) + (y-v) * (y-v);
}

int main()
{
    int n, k;
    vector<int> a(1005);
    vector<int> x(1005), y(1005);

    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> a.at(i);

    for (int i = 1; i <= n; i++) cin >> x.at(i) >> y.at(i);
    
    ll ans = 0, tmp = 1L<<58;

    for (int j = 1; j <= n; j++) {
        for (int i = 0; i < k; i++) {
            tmp = min(tmp, f(x.at(a.at(i)), y.at(a.at(i)), x.at(j), y.at(j)));
            // cout << tmp << endl;
        }
        ans = max(ans, tmp);
        tmp = 1L<<58;
        // cout << " ans " << ans << endl;
    }

    cout << fixed << setprecision(12) << sqrt(ans) << endl;

    return 0;
}