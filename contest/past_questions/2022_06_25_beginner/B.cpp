#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, q;
    vector<int> a(205);

    cin >> n >> k >> q;
    for (int i = 1; i <= k; i++) cin >> a.at(i);
    for (int i = 0; i < q; i++) {
        int l;
        cin >> l;
        if (a.at(l) == n) continue;
        if (l < k && a.at(l+1) == a.at(l)+1) continue;

        a.at(l)++;
    }
    for (int i = 1; i <= k; i++) cout << a.at(i) << " ";

    return 0;
}