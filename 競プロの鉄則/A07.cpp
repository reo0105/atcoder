#include <bits/stdc++.h>
using namespace std;

int main()
{
    int d, n;
    vector<int> a(100002, 0);

    cin >> d >> n;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        a.at(l) += 1;
        a.at(r+1) -= 1;
    }

    int ans = 0;
    for (int i = 1; i <= d; i++) {
        ans += a.at(i);
        cout << ans << endl;
    }

    return 0;
}