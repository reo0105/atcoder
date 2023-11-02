#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+4);
    
    for (int i = 1; i <= n; i++) cin >> a[i];

    vector<vector<int>> sta(n+1);
    vector<ll> add(n+1, 0);

    sta[a[1]].push_back(1);
    sta[a[2]].push_back(2);
    ll ans = 0;
    for (int i = 3; i <= n; i++) {
        int now = a[i];
        sta[now].push_back(i);
        int sz = (int)sta[now].size();
        if (sz == 1) continue;
        ans += add[now];
        add[now] += (ll)(i - sta[now][sz-2] - 1) * (sz - 1);
        ans += (ll)(i - sta[now][sz-2] - 1) * (sz - 1);
    }

    cout << ans << endl;

    return 0;
}