#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1L<<62

int main()
{
    int n, m;
    vector<ll> a(200005);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<ll> sum(200005, 0);
    for (int i = 1; i <= n; i++) sum.at(i) = sum.at(i-1) + a.at(i);

    ll now = 0, ans = 0; //0初期化してミスってた
    for (int i = 1; i <= m; i++) now += i*a.at(i);

    ans = now;
    for (int i = 2; i <= n-m+1; i++) {
        now += m*a.at(i+m-1) - (sum.at(i+m-2) - sum.at(i-2));
        // cout << now << " ";
        ans = max(ans, now);
    }
    // cout << endl;
    cout << ans << endl;

    return 0;
}