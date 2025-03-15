#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    if (k % 2 == 0) {
        int ans = 0;
        for (int i = 0; i < k/2; i++) {
            int a, b;
            cin >> a >> b;
            ans += b-a;
        }
        cout << ans << endl;
    } else {
        vector<int> a(k);

        for (int i = 0; i < k; i++) cin >> a[i];

        vector<int> sum(k, 0);
        vector<int> rsum(k, 0);

        for (int i = 0; i < k/2; i++) sum[i+1] = sum[i] + a[2*i+1] - a[2*i];
        for (int i = 0; i < k/2; i++) rsum[i+1] = rsum[i] + a[k-2*i-1] - a[k-2*i-2];

        int ans = (k == 1) ? 0 : 1e9;
        for (int i = 0; i < k/2+1; i++) {
            ans = min(ans, sum[i]+rsum[k/2-i]);
        }

        cout << ans << endl;

    }

    return 0;
}