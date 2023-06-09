#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    vector<int> x(300005);
    for (int i = 0; i < n; i++) cin >> x.at(i);

    int l = 1, r = 1e9+5;

    while (r - l > 1) {
        long long cnta = 0;
        long long cntb = 0;
        int mid = (l + r) / 2;
        for (int i = 0; i < n; i++) {
            int diff = x.at(i) - mid;
            if (diff >= 0) cntb += diff / b;
            else cnta += (abs(diff) - 1) / a + 1;
        }

        if (cnta > cntb) r = mid;
        else l = mid;
    }

    cout << l << endl;

    return 0;
}