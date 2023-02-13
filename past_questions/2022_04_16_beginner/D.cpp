#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n, q;
    vector<vector<p>> a(200005);
    vector<int> cnt(200005, 1);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.at(x).push_back(make_pair(i, cnt.at(x)));
        cnt.at(x)++;
    }
    cin >> q;

    for (int i = 0; i < q; i++) {
        int l, r, x;
        cin >> l >> r >> x;

        auto itrl = lower_bound(a.at(x).begin(), a.at(x).end(), make_pair(l, 0));
        auto itrr = upper_bound(a.at(x).begin(), a.at(x).end(), make_pair(r, 200005));

        if (itrl == itrr) {
            cout << 0 << endl;
        } else {
            itrr--;
            if (itrl == itrr) {
                cout << 1 << endl;
            } else {
                int ans = (*itrr).second - (*itrl).second + 1;
                cout << ans << endl;
            }
        }
    }

    return 0;
}