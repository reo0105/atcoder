#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m, k;
    vector<int> a(200005);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) cin >> a.at(i);

    int ans = 0;
    int mask = 0x40000000;
    ll cnt = 0;

    for (int i = 0; i < 32; i++) {
        vector<int> add;
        for (int j = 0; j < n; j++) {
            add.push_back(max(mask - a.at(j), 0));
            if (a.at(j) & mask) a.at(j) ^= mask;
        }

        sort(add.begin(), add.end());
        cnt = 0;
        for (int j = 0; j < k; j++) {
            cnt += add.at(j);
        }

        if (cnt <= m) {
            ans |= mask;
            m -= cnt;
        }

        mask >>= 1;
    }

    cout << ans << endl;

    return 0;
}