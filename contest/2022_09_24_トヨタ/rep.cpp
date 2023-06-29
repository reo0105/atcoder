#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    ll k;
    vector<ll> a(100005);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a.at(i);

    ll l = 0, r = 1e12+2, cnt, mid;

    while (r - l > 1) {
        mid = (r + l) / 2;

        cnt = 0;
        for (int i = 0; i < n; i++) {
            if (a.at(i) <= mid) cnt += a.at(i);
            else cnt += mid;
        }

        if (cnt >= k) r = mid;
        else l = mid;
    }

    cnt = 0;
    for (int i = 0; i < n; i++) {
        cnt += min(l, a.at(i));
        a.at(i) = max(0LL, a.at(i) - l);
    }

    for (int i = 0; i < n; i++) {
        if (a.at(i) > 0) {
            a.at(i)--;
            cnt++;
        }
        if (cnt == k) break;
    }

    for (int i = 0; i < n; i++) cout << a.at(i) << " ";
    cout << endl;

    return 0;
}