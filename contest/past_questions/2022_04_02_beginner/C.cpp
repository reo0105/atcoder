#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, k, x;
    vector<int> a(200005);

    cin >> n >> k >> x;
    for (int i = 0; i < n; i++) cin >> a.at(i);

    sort(a.rbegin(), a.rend());

    int cnt = 0, flag = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int t;
        t = a.at(i) / x;
        a.at(i) -= t*x;
        cnt += t;
        if (cnt >= k) {
            t = cnt - k;
            a.at(i) += t*x;
            flag = 1;
            break;
        } 
    }

    sort(a.rbegin(), a.rend());

    if (flag == 0) {
        for (int i = 0; i < n; i++) {
            a.at(i) = 0;
            cnt++;
            if (cnt == k) break;
        }
    }

    for (int i = 0; i < n; i++) ans += a.at(i);

    cout << ans << endl;

    return 0;
}