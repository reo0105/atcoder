#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    vector<int> a(100002, 0);

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.at(i) = a.at(i-1) + x;
    }

    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        int ans = a.at(r) - a.at(l-1);
        cout << ans << endl;
    }

    return 0;
}