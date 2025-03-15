#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    
    int n;
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> front(300005, 0L);
    vector<ll> back(300005, 0L);

    for (int i = 0; i < n; i++) front[a[i]]++;

    ll ans = 0;
    ll t = 0;
    int pre = a[0];
    front[pre]--;
    for (int j = 1; j < n-1; j++) {
        int now = a[j];

        t -= front[now] * back[now];
        if (now != pre) t -= front[pre] * back[pre];
        // cout << t << " "; 
        front[now]--;
        back[pre]++;
        t += front[now] * back[now];
        if (now != pre) t += front[pre] * back[pre];
        pre = now;
        ans += t - front[now] * back[now];
        // cout << ans << " " << now << " " << front[now] << " " << back[now] << endl;
    }
    cout << ans << endl;

    return 0;
}