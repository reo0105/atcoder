#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, l;
    vector<int> a, b, c;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }

    cin >> m;
    for (int i = 0; i < m; i++) {
        int t;
        cin >> t;
        b.push_back(t);
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        int t;
        cin >> t;
        c.push_back(t);
    }

    set<int> st;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < l; k++) {
                st.insert(a[i] + b[j] + c[k]);
            }
        }
    }

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int x;
        cin >> x;
        if (st.count(x)) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}