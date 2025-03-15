#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, ll> p;

int main()
{
    ll l;
    int n1, n2;
    vector<p> a0(100005), a1(100005);

    cin >> l >> n1 >> n2;
    for (int i = 0; i < n1; i++) cin >> a0.at(i).first >> a0.at(i).second;
    for (int i = 0; i < n2; i++) cin >> a1.at(i).first >> a1.at(i).second;

    int j = 0;
    ll id0 = 0, id1 = 0;
    ll ans = 0;
    for (int i = 0; i < n1; i++) {
        p t0 = a0.at(i);
        int v0 = t0.first;
        ll l0 = t0.second;

        while (id1 < id0 + l0) {
            p t1 = a1.at(j);
            int v1 = t1.first;
            ll l1 = t1.second;

            // cout << id0 <<  " " << id1 << " " << i  << " " << j  << " "  << ans  << " " << l0 << " " << l1 << endl;

            if (v0 == v1) {
                if (id1 + l1 < id0 + l0) {
                    ans += (l1);
                    id1 += l1;
                    j++;
                    // cout << "id1" << endl;
                } else {
                    a1.at(j).second -= (l0+id0-id1);
                    if (id1 + l1 == id0 + l0) j++;
                    ans += (id0+l0-id1);
                    id1 += (l0+id0-id1);
                    // cout << "id2" << endl;
                }
            } else {
                if (id1 + l1 < id0 + l0) {
                    // cout << "id3" << endl;
                    id1 += l1;
                    j++;
                } else {
                    a1.at(j).second -= (l0+id0-id1);
                    if (id1 + l1 == id0 + l0) j++;
                    id1 += (l0+id0-id1);
                    // cout << "id4" << endl;
                }
            }
            // if (id0 > id1+l1) j++;
        }
        id0 += l0;
    }

    cout << ans << endl;

    return 0;
}