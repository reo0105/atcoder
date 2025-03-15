#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> x(m);
    vector<ll> sum(n+5, 0);

    for (int i = 0; i < m; i++) cin >> x[i];

    for (int i = 0; i < m-1; i++) {
        int u, v;
        u = x[i];
        v = x[i+1];

        if (u > v) swap(u, v);

        int dist = v - u;
        sum[u] += n-dist;
        sum[v] -= n-dist;

        sum[v] += dist;
        sum[n+1] -= dist;

        if (u != 1) {
            sum[1] += dist;
            sum[u] -= dist;
        }
    }

    for (int i = 0; i < n+3; i++) {
        sum[i+1] += sum[i];
    }

    ll ans = sum[1];
    for (int i = 1; i <= n; i++) ans = min(ans, sum[i]);

    cout << ans << endl;

}