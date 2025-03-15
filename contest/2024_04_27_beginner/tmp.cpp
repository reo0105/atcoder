#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

typedef pair<int, int> pii;
typedef long long ll;

int main() {
    int n;
    cin >> n;

    vector<pii> a(n);
    vector<int> b(n);
    map<int, int> num_to_id;
    
    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
        b[i] = a[i].first;
    }

    sort(a.begin(), a.end());
    
    set<int> st;
    for (int i = 0; i < n; i++) {
        int ai = a[i].first;
        st.insert(ai);
        num_to_id[ai] = (int)st.size();
    }

    fenwick_tree<ll> fsum(n+3);
    fenwick_tree<int> fcnt(n+3);

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int ai = num_to_id[b[i]];
        ans += (ll)b[i] * fcnt.sum(0, ai);
        ans -= fsum.sum(0, ai); 

        fcnt.add(ai, 1);
        fsum.add(ai, b[i]);

        // cout << ai << " " << b[i] << endl;
        // cout << ans << endl;
    }

    cout << ans << endl;

    return 0;
}