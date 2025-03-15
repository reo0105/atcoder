#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> a;
    unordered_map<int, int> mp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        mp[x]++;
    }
    sort(a.begin(), a.end());

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int ai = a.at(i);

        vector<int> fac;
        for (int j = 1; j*j <= ai; j++) {
            if (ai % j != 0) continue;

            fac.push_back(j);

            if (ai / j != j) fac.push_back(ai / j);
        }

        for (int x : fac) {
            if (mp.count(x) && mp.count(ai/x)) {
                ans += (ll)mp[x] * mp[ai/x];
            }
        }
    }

    cout << ans << endl;
 
    return 0;
}