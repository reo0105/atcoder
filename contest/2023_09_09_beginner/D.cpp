#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> L(n);
    for (int i = 0; i < n; i++) cin >> L[i];

    ll l = 0, r = 4e18;

    while (r - l > 1) {
        ll mid = (l + r) / 2;

        ll mojir = 0;
        int row = 1;

        for (int i = 0; i < n; i++) {
            int li = L[i];
            if (li > mid) { row = m + 1; break; }
            if (mojir + li > mid) {
                row++;
                mojir = li + 1;
            } else {
                mojir += li + 1;
            }
        }

        if (row <= m) r = mid;
        else l = mid;
    }

    cout << r << endl;

    return 0;
}