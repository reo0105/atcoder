#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];

    ll mini = 1e9;
    ll now = 0;

    for (int i = 0; i < n; i++) {
        now += a[i];
        mini = min(mini, now);
    }

    now = max(-mini, 0LL);

    for (int i = 0; i < n; i++) now += a[i];

    cout << now << endl;

    return 0;
}