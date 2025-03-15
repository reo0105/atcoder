#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> xs(q);
    for (int i = 0; i < q; i++) cin >> xs[i];

    vector<ll> ans(n, 0);
    set<int> st;
    vector<int> insert(n, -1);
    vector<ll> sum(q+1, 0);


    for (int i = 0; i < q; i++) {
        int x = xs[i] - 1;

        if (st.count(x)) {
            st.erase(x);
            // add
            ans[x] += sum[i] - sum[insert[x]];
            insert[x] = -1;
            // cout << x << " "
        } else {
            st.insert(x);
            insert[x] = i;
        }
        sum[i+1] = sum[i] + (int)st.size();

    }

    for (int i = 0; i < n; i++) {
        if (insert[i] != -1) {
            ans[i] += sum[q] - sum[insert[i]];
        }
    }

    for (int i = 0; i < n; i++) cout << ans[i] << " ";
    cout << endl;

    return 0;
}