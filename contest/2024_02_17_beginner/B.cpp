#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

int main()
{
    int n;
    cin >> n;

    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<pii> st(n-1);

    for (int i = 0; i < n-1; i++) {
        cin >> st[i].first >> st[i].second;
    }

    for (int i = 0; i < n-1; i++) {
        ll now = a[i];

        a[i+1] += st[i].second * (now / st[i].first);
    }

    cout << a[n-1] << endl;

    return 0;
}