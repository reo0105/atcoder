#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> a(500005);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    ll ans = 0, same = 0;

    for (int i = 1; i <= n; i++) {
        int t = a.at(i);
        if (i == t) { same++; continue; }
        if (i == min(a.at(i), a.at(t)) && t == max(a.at(i), a.at(t))) {
            ans++;
            // cout << i << " " << t << endl;
        }
    }

    cout << ans + (same-1)*same/2 << endl;

    return 0;
}