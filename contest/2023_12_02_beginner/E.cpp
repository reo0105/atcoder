#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, int> pii;

int main()
{
    int n, m, l;
    cin >> n >> m >> l;

    vector<ll> a(n);
    vector<pii> b(m);
    vector<vector<int>> L(n+1);

    for (int i = 0; i < n; i++) cin >> a[i]; 
    for (int i = 0; i < m; i++) { cin >> b[i].first; b[i].second = i; }
    for (int i = 0; i < l; i++) {
        int c, d;
        cin >> c >> d;
        L[c].push_back(d);
    }

    sort(b.rbegin(), b.rend());

    vector<int> ids(m+1, 0);
    vector<int> ids_inv(m+1, 0);
    for (int i = 0; i < m; i++) {
        ids[b[i].second] = i;
        ids_inv[i] = b[i].second;
    }


    ll ans = 0;

    for (int i = 0; i < n; i++) {
        if (L[i+1].empty()) {
            ans = max(ans, a[i] + b[0].first);
        } else {
            int id = 0;
            vector<bool> ng(m+3, true);
            for (int j : L[i+1]) {
                j--;        
                ng[ids[j]] = false;
            }

            int li;
            for (li = 0; li < m; li++) {
                if (ng[li]) { id = li; break; }
            }

            // cout << id << " ";

            if (li != m) {
                // id = ids_inv[id];
                // cout << id << " ";
                ans = max(ans, a[i] + b[id].first);
                // cout << ans << endl;
            }
        }
    }

    cout << ans << endl;

    return 0;
}