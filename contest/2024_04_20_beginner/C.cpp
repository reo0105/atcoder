#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> ids(n+1);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        ids[a[i]] = i;
    }

    int k = 0;
    vector<pii> ans;

    for (int i = 0; i < n; i++) {
        int num = ids[i+1];
        if (num != i) {
            k++;
            ans.push_back(make_pair(min(num, i), max(num, i)));
            swap(ids[i+1], ids[a[i]]);
            swap(a[i], a[num]);
        }
        // for (int i = 0; i < n; i++) cout << a[i] << " ";
        // cout << endl;
        // for (int i = 1; i < n+1; i++) cout << ids[i] << " ";
        // cout << endl;
    }

    cout << k << endl;
    for (int i = 0; i < k; i++) cout << ans[i].first+1 << " " << ans[i].second+1 << endl;

    return 0;
}