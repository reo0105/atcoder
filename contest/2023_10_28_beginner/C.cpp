#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    sort(a.begin(), a.end());

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int now = a[i];

        int lim = upper_bound(a.begin(), a.end(), now + m -1) - a.begin() - i;
        ans = max(ans, lim);
    }

    cout << ans << endl;

    return 0;
}