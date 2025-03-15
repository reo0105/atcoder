#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    multiset<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }

    long long ans = 0;
    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;

        auto itr = a.lower_bound(b);
        if (itr == a.end()) {
            cout << -1 << endl;
            return 0;
        }

        int mini = *itr;
        a.erase(itr);
        ans += mini;
    }

    cout << ans << endl;
    return 0;
}