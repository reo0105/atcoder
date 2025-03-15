#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;


int main()
{
    int n;
    vector<int> l, r;

    cin >> n;
    int maxi = -1, mini = 1e9;
    for (int i = 1; i <= n; i++) {
        int tl, tr;
        cin >> tl >> tr;
        maxi = max(maxi, tl);
        mini = min(mini, tr);
        l.push_back(tl);
        r.push_back(tr);
    }

    sort(l.rbegin(), l.rend());
    sort(r.begin(), r.end());

    ll ans = 0;

    if (maxi <= mini) cout << 0 << endl;
    else {
        for (int i = 0; i < n; i++) {
            ans += (ll)max(0, l.at(i) - r.at(i)) * (n-2*i-1);
        }
        cout << ans << endl;
    }

    return 0;
}