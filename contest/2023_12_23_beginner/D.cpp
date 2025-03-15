#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> r(n);
    for (int i = 0; i < n; i++) cin >> r[i];

    sort(r.begin(), r.end());

    vector<ll> sum(n, 0);
    sum[0] = r[0];
    for (int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + r[i];
    }

    for (int i = 0; i < q; i++) {
        ll x;
        cin >> x;

        cout << upper_bound(sum.begin(), sum.end(), x) - sum.begin() << endl;
    }


    return 0;
}