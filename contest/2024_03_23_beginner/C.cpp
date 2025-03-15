#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;

    ll ans = (ll)k * (ll)(k+1) / 2;

    set<int> st;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (st.count(a)) continue;
        if (a > k) continue;
        ans -= a;
        st.insert(a);
    }

    cout << ans << endl;

    return 0;
}