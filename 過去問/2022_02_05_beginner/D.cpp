#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    // vector<ll> a(100005), s(100005);
    cin >> t;

    for (int i = 0; i < t; i++) {
        ll a, s;
        cin >> a >> s;
        
        vector<bool> used(65, false);
        int cnt = 0;
        while (a >> cnt) {
            if ((a >> cnt) & 1) used.at(cnt) = true;
            cnt++;
        }

        s -= 2*a;

        cnt = 0;
        int flag = 0;

        if (s < 0) flag = 1;
        else {
            while (s >> cnt) {
                if (((s >> cnt) & 1) && used.at(cnt)) {
                    flag = 1;
                    break;
                }
                cnt++;
            }
        }

        if (flag) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}