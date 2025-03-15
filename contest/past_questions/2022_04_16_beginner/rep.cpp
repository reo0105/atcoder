#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353
typedef long long ll;

int main()
{
    int n, k;
    vector<int> x(305), y(305);
    vector<vector<bool>> done(305, vector<bool>(305, false));

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x.at(i) >> y.at(i);
    }


    if (k == 1) cout << "Infinity" << endl;
    else {
        int ans = 0;
        for (int p = 0; p < n; p++) {
            for (int q = p+1; q < n; q++) {
                if (done.at(p).at(q)) continue;

                vector<int> now;
                now.push_back(p); now.push_back(q);

                ll vx0 = x.at(q) - x.at(p);
                ll vy0 = y.at(q) - y.at(p);
                int cnt = 2;

                for (int s = q+1; s < n; s++) {
                    ll vx1 = x.at(s) - x.at(p);
                    ll vy1 = y.at(s) - y.at(p);

                    if (vx0*vy1 == vx1*vy0) {
                        cnt++;
                        now.push_back(s);
                    }
                }

                if (cnt >= k) ans++;

                int sz = (int)now.size();
                for (int i = 0; i < sz; i++) {
                    for (int j = i+1; j < sz; j++) {
                        if (i == j) continue;
                        done.at(now.at(i)).at(now.at(j)) = true;
                        done.at(now.at(j)).at(now.at(i)) = true;
                    }
                }
                
            }
        }

        cout << ans << endl;
    }

    return 0;
}