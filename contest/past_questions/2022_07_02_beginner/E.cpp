#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int n, q, x;
    vector<int> w(200005);
    vector<ll> sum(400005, 0);

    cin >> n >> q >> x;
    for (int i = 1; i <= n; i++) cin >> w.at(i);

    for (int i = 1; i < 2*n; i++) {
        if (i <= n) sum.at(i) = sum.at(i-1) + w.at(i);
        else sum.at(i) = sum.at(i-1) + w.at(i-n);
    }

    int now = 1;
    int l = 0, r = 2*n-1;
    ll total = sum.at(n) - sum.at(0);
    vector<p> cnt;
    set<int> done;
    

    while (1) {
        r = 2*n-1;
        int time = x / total;
        int tx = x - time * total;
        while (r - l > 1) {
            int mid = (l+r) / 2;
            // cout << "l, r " << l << " " << r << " " << mid << " " << sum.at(mid) << endl;;
            if (sum.at(mid) - sum.at(now-1) >= tx) r = mid;
            else l = mid;
        }
        cout << "l, r " << l << " " << r << endl;
        cnt.push_back(make_pair(now, r-now+1+time*n));
        if (done.count(now)) break;

        done.insert(now);
        if (r >= n) r-=n;
        now = r+1;
        l = r+1;
    }

    int id = (int)cnt.size() - 1;
    ll loop;
    for (int i = 0; i < id; i++) {
        // cout << cnt.at(i).first << " " << cnt.at(i).second << endl;
        if (cnt.at(i).first == cnt.at(id).first) {
            loop = id - i;
        }
    }

    int re = id - loop;
    cout << loop << " " << re << endl;

    for (int i = 0; i < q; i++) {
        ll k;
        cin >> k;
        ll ans;
        if (k <= re) ans = k-1;
        else ans = re + (k - re - 1) % loop;
        // cout << ans << " ";
        cout << cnt.at(ans).second << endl;
    }

    return 0;
}