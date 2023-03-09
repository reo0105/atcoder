#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, m, t;
    vector<int> a(100005);
    vector<int> x(100005, 0), y(100005, 0);

    cin >> n >> m >> t;
    for (int i = 1; i <= n-1; i++) cin >> a.at(i);
    for (int i = 1; i <= m; i++) cin >> x.at(i) >> y.at(i);

    int bonus = 1;
    int now = 1;
    while (t > 0) {
        t -= a.at(now);
        if (t <= 0) break;
        now++;
        if (x.at(bonus) == now) {
            t += y.at(bonus);
            bonus++;
        }
        if (now == n) break;
    }

    if (now == n) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}