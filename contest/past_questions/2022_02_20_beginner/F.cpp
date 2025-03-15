#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

int main()
{
    int t;
    vector<ll> x(200005), y(200005);

    cin >> t;
    for (int i = 0; i < t; i++) {
        int n, m;
        cin >> n >> m;

        for (int j = 0; j < n; j++) cin >> x.at(j) >> y.at(j);

        ll ans = -1e9;
        ll a = 0, b = 0;

        for (int j = 0; j < n; j++) {
            ans = max(ans, a + b + x.at(j));
            // cout << b << " " << a << " " << endl;
            if (b > 0 && x.at(j) < 0) {
                ll incre = (b / -x.at(j));
                if (incre < y.at(j)) {
                    // int first = b + x.at(j);
                    // cout << first << " " << (2*first + (incre - 1) * x.at(j+1)) * incre / 2 << endl;
                    ans = max(ans, a + b * incre + x.at(j) * (incre + 1) * incre / 2);
                }
            } 
            a = a + b * y.at(j) + x.at(j) * (y.at(j) + 1) * y.at(j) / 2;
            b = b + x.at(j) * y.at(j);
            ans = max(ans, a);    
        }

        cout << ans << endl;      
    }

    return 0;
}