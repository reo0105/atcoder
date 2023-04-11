#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;

int main()
{
    int n, k;
    vector<int> x(305), y(305);

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x.at(i) >> y.at(i);
    }


    if (k == 1) cout << "Infinity" << endl;
    else {
        int ans = 0;
        for (int p = 0; p < n; p++) {
            for (int q = p+1; q < n; q++) {
                ll vx0 = x.at(q) - x.at(p);
                ll vy0 = y.at(q) - y.at(p);
                int cnt = 2;

                for (int s = q+1; s < n; s++) {
                    ll vx1 = x.at(s) - x.at(p);
                    ll vy1 = y.at(s) - y.at(p);

                    if (vx0*vy1 == vx1*vy0) cnt++;
                }

                if (cnt >= k) ans++;

                
            }
        }
    }
}