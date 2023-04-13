#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll l;
    priority_queue<ll, vector<ll>, greater<ll>> que;
    // vector<int> a(200005);

    cin >> n >> l;
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        sum += x;
        que.push(x);
    }

    if (sum != l) que.push(l-sum);

    ll ans = 0;
    while (que.size()) {
        ll mini0 = que.top();
        que.pop();

        if (que.empty()) break;

        ll mini1 = que.top();
        que.pop();

        ll t = mini0 + mini1;
        ans += t;
        que.push(t);
    }

    cout << ans << endl;

    return 0;
}