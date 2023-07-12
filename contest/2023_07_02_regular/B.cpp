#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a;

    int a0, a1;
    cin >> a0 >> a1;
    for (int i = 2; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    ll ans = 2e18;
    for (int i = 0; i <= n-2-m; i++) {
        ll t = 0;
        if (a0 > a.at(i)) t += a0 - a.at(i);
        if (a1 < a.at(i+m-1)) t += a.at(i+m-1) - a1;

        ans = min(ans, t);
    }

    cout << ans << endl;

}