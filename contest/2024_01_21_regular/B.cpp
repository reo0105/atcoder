#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> r(n+3);
    vector<vector<int>> num(11);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        num[a[i]].push_back(i);
    }

    ll ans = 0;

    for (int i = 0; i < n; i++) {
        int ai = a[i];
        r[i] = n;
        for (int aj = 1; aj <= 10; aj++) {
            int diff = aj - ai;
            int ak = aj + diff;
            if (ak <= 0 || 11 <= ak) continue;

            auto itr_j = upper_bound(num[aj].begin(), num[aj].end(), i);
            if (itr_j == num[aj].end()) continue;

            int j = *itr_j;
            auto itr_k = upper_bound(num[ak].begin(), num[ak].end(), j);
            if (itr_k == num[ak].end()) continue;

            int k = *itr_k;

            r[i] = min(r[i], k);

        }
    }

    for (int i = n-1; i >= 0; i--) r[i] = min(r[i], r[i+1]);

    for (int i = 0; i < n; i++) ans += n-r[i];

    cout << ans << endl;

    return 0;    
}