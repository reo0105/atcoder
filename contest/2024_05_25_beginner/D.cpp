#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;

    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) cin >> l[i] >> r[i];

    ll ans = (ll)n * (n-1) / 2;

    sort(l.begin(), l.end());
    sort(r.begin(), r.end());

    for (int ri : r) {
        int cnt = l.end() - upper_bound(l.begin(), l.end(), ri);
        ans -= cnt;
    }

    cout << ans << endl;

    return 0;
}