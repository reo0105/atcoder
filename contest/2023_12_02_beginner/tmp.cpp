#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n, m, l;
    cin >> n >> m >> l;

    vector<pii> a(n), b(m);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    for (int i = 0; i < m; i++) {
        cin >> b[i].first;
        b[i].second = i;
    }

    vector<set<int>> st(n);
    for (int i = 0; i < l; i++) {
        int c, d;
        cin >> c >> d;
        c--; d--;
        st[c].insert(d);
    }

    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());

    set<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!st[a[i].second].count(b[j].second)) {
                ans.insert(a[i].first + b[j].first);
                // cout << a[i].first << " " << b[j].first << endl;
                break;
            }
        }
    }

    cout << *rbegin(ans) << endl;
    

    return 0;
}