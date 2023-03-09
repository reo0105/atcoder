#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    vector<int> s(100005);
    vector<int> x(15);

    cin >> n >> m;
    for (int i = 0; i < n-1; i++) cin >> s.at(i);
    for (int i = 0; i < m; i++) cin >> x.at(i);

    map<ll, ll> mp;
    ll a = 0, c = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            mp[(x.at(j)-a)*c]++;
        }
        a = s.at(i) - a;
        c = -c;
    }

    ll ans = 0;
    for (auto p : mp) ans = max(ans, p.second);
    cout << ans << endl;

    return 0;
}