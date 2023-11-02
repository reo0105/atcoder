#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, d, p;

    cin >> n >> d >> p;

    vector<int> f;

    double per = p / d;
    int ov = 0;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        f.push_back(x);
        if (x >= per) ov++;
    }

    sort(f.rbegin(), f.rend());

    int buy = ov / d;

    ll ans = 1e18;
    for (int i = buy -2; i <= buy + 2; i++) {
        if (i < 0) continue;
        ll tmp = (ll)p * i;
        for (int j = i*d; j < n; j++) {
            tmp += f[j];
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}