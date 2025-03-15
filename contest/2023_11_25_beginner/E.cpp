#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    unordered_map<int, int> cnt;
    unordered_set<int> notin;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 0; i <= n; i++) {
        if (cnt[i] == 0) notin.insert(i);
    }

    for (int i = 0; i < q; i++) {
        int qi, xi;
        cin >> qi >> xi;
        qi--;

        int replace = a[qi];
        a[qi] = xi;

        cnt[replace]--;
        cnt[xi]++;

        if (cnt[replace] == 0) notin.insert(replace);
        if (cnt[xi] == 1) notin.erase(xi);

        cout << *begin(notin) << "\n";
    }

    return 0;
}