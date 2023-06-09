#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int n, q, x;
    cin >> n >> q >> x;

    vector<int> w(200005);
    for (int i = 1; i <= n; i++) cin >> w.at(i);

    set<int> done;
    vector<p> boxes;

    int now = 0;
    int start = 1;
    int cnt = 0;

    vector<ll> sum(400005, 0);
    for (int i = 1; i <= 2*n; i++) {
        if (i <= n) sum.at(i) = sum.at(i-1) + w.at(i);
        else sum.at(i) = sum.at(i-1) + w.at(i-n);
    }


    ll total = sum.at(n);
    int l = 0, r = 2*n;
    while (1) {
        int loopcnt = (x-1) / total;
        cnt = loopcnt * n;
        ll num = sum.at(n) * loopcnt;
        ll tx = x - num;

        r = 2*n;
        while (r - l > 1) {
            int mid = (l + r) / 2;
            if (sum.at(mid) - sum.at(start-1) >= tx) r = mid;
            else l = mid;
        }
        cnt += r - start + 1;

        if (done.count(start)) break;

        boxes.push_back(make_pair(start, cnt));
        done.insert(start);
        r %= n;
        start = r+1;
        l = r;
    }

    int sz = (int)boxes.size();
    int nl = 0;
    for (int i = 0; i < n; i++) {
        if (boxes.at(i) == make_pair(start, cnt)) break;
        nl++;
    }

    l = sz - nl;

    // for (auto p : boxes) {
    //     cout << p.first << " " << p.second << endl;
    // }

    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;
        if (k <= nl) {
            cout << boxes.at(k-1).second << endl;
        } else {
            k -= nl;
            // cout << nl + ((k-1) % l) << endl;
            cout << boxes.at(nl + (k-1) % l).second << endl;
        }
    }
    

    return 0;
}