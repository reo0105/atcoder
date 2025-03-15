#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m, k;
    vector<int> a;

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    int ans = 0;
    int mask = (1<<31)-1;
    ll cnt = 0;
    int flag = 1;

    for (int i = 30; i >= 0; i--) {
        for (int j = 0; j < n; j++) {
            a.at(j) &= mask;
        }

        if (flag) sort(a.rbegin(), a.rend());
        
        cnt = 0;
        for (int j = 0; j < k; j++) {
            if (((a.at(j)>>i) & 1) == 0) {
                cnt += (1<<i) - a.at(j);
            }
        }

        if (cnt <= m) {
            ans |= 1<<i;
            m -= cnt;

            if (cnt == 0) {
                for (int j = 0; j < n; j++) {
                    if (((a.at(j)>>i) & 1) == 0) {
                        a.at(j) = 0;
                    }
                }
            } else {
                for (int j = 0; j < k; j++) {
                    if (((a.at(j)>>i) & 1) == 0) {
                        a.at(j) = 1<<i;
                    }
                }
                flag = 0;
            }
        }

        mask >>= 1;
    }

    cout << ans << endl;

    return 0;
}