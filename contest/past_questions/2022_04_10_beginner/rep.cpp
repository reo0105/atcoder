#include <bits/stdc++.h>
using namespace std;
<<<<<<< HEAD
#define MOD 998244353
=======
typedef pair<int, int> p;
>>>>>>> efdf3965130a0de7b66a14ab5434de7f81498d8a
typedef long long ll;

int main()
{
<<<<<<< HEAD
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
=======
    int n, x, y;
    vector<int> a(200005);

    cin >> n >> x >> y;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    int posx = -1, posy = -1;
    int b = 0;
    ll ans = 0;

    for (int i = 1; i <= n; i++) {
        if (a.at(i) == x) posx = i;
        if (a.at(i) == y) posy = i;
        if (a.at(i) < y || x < a.at(i)) b = i;
        // cout << i << " " << posx << " " << posy << " " << b << endl;
        ans += max(0, min(posx, posy) - b);
    }

    cout << ans << endl;

    return 0;
>>>>>>> efdf3965130a0de7b66a14ab5434de7f81498d8a
}