#include <bits/stdc++.h>
using namespace std;
#define INF 1e9
typedef long long ll;

int main()
{
    int n;
    vector<int> a(300005);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a.at(i);

    vector<int> cnt(32, 0);
    ll ans = 0;
    int dim = 0;

    for (int i = 0; i < n; i++) {
        int t = 0;
        while (a.at(i) >> t) t++;
        dim = max(dim, t);
    }

    for (int i = 0; i < n; i++) {
        for (int j = dim; j >= 0; j--) {
            if ((a.at(i) >> j) & 1) cnt.at(j)++;
        }
        ans += a.at(i);
    }

    for (int i = 0; i < n; i++) {
        int choose = a.at(i);
        ll tmp = 0, two = 1;
        for (int j = 0; j < dim; j++) {
            if (choose & 1) tmp += two * (n-cnt.at(j));
            else tmp += two * cnt.at(j);

            two *= 2;
            choose >>= 1;
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}