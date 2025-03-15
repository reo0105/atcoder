#include <bits/stdc++.h>
using namespace std;

typedef long long ll;


int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> b(n), w(m);
    for (int i = 0; i < n; i++) cin >> b[i];
    for (int i = 0; i < m; i++) cin >> w[i];

    sort(b.rbegin(), b.rend());
    sort(w.rbegin(), w.rend());

    ll ans = 0;
    for (int i = 0; i < min(n, m); i++)
    {
        if (b[i] < 0 && w[i] < 0) break;
        else if (b[i] > 0 && w[i] > 0) ans += b[i] + w[i];
        else if (b[i] > 0 && w[i] < 0) ans += b[i];
        else if (b[i] < 0 && w[i] > 0 && w[i] + b[i] >= 0) ans += b[i] + w[i];
    }

    for (int i = min(n, m); i < n; i++) 
    {
        if (b[i] > 0) ans += b[i];
    }

    cout << ans << endl;

    return 0;
}