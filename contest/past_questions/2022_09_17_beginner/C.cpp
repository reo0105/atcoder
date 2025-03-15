#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    vector<int> bits;
    cin >> n;

    for (int i = 0; i < 62; i++) {
        if (((n>>i) & 1 ) == 1) {
            bits.push_back(i);
        }
    }

    int si = (int)bits.size();

    for (int i = 0; i < (1<<si); i++) {
        ll ans = 0;
        for (int j = 0; j < si; j++) {
            if (((i>>j) & 1) != 1) continue;

            ans += (1LL<<bits.at(j));
        }

        cout << ans << endl;
    }

    return 0;
}