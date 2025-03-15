#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        q--;
        p[q] = i;
    }

    set<int> st;
    for (int i = 0; i < k; i++) st.insert(p[i]);

    int ans = *rbegin(st) - *begin(st);
    for (int i = 0; i < n-k; i++) {
        int idx = p[i];
        st.erase(idx);
        st.insert(p[i+k]);

        ans = min(ans, *rbegin(st) - *begin(st));
    }
    cout << ans << endl;

    return 0;
}