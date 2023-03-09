#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

int main()
{
    ll n, p, q, r;
    vector<int> a(200005);

    cin >> n >> p >> q >> r;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<ll> sum(1, 0);

    for (int i = 1; i <= n; i++) {
        ll t = sum.at(i-1) + a.at(i);
        sum.push_back(t);
    }

    // for(int i = 0; i <= n; i++) cout << sum.at(i) << " ";
    // cout << endl;

    for (int xi = 1; xi <= n-2; xi++) {
        ll x = sum.at(xi-1);
        ll idy = lower_bound(sum.begin(), sum.end(), x + p) - sum.begin();
        // cout << "x : " << x << " " << idy << endl;
        if (idy > n || sum.at(idy)-x != p) continue;

        ll y = sum.at(idy);
        ll idz = lower_bound(sum.begin(), sum.end(), y + q) - sum.begin();
        // cout << "y : " << y << " " << idz << endl;
        if (idz > n || sum.at(idz)-y != q) continue;

        ll z = sum.at(idz);
        ll idw = lower_bound(sum.begin(), sum.end(), z + r) - sum.begin();
        // cout << "z : " << z << " " << idw << endl;
        if (idw > n || sum.at(idw)-z != r) continue;

        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}