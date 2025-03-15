#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, t, cnt = 0, s;
    vector<int> a(100002);
    cin >> n >> t;

    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        cnt += a.at(i);
    }

    s = t % cnt;

    cnt = 0;
    int i;
    for (i = 0; i < n; i++) {
        cnt += a.at(i);
        if (cnt > s) break;
    }
    cnt -= a.at(i);

    cout << i+1 << " " << s-cnt << endl;

    return 0;
}