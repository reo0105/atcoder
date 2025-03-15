#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;

int main()
{
    ll n, k;
    vector<int> a(200005);
    map<int, p> m;

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a.at(i);

    ll i;
    ll cnt = 0;
    for (i = 0; i < k; i++) {
        // cout << cnt << endl;
        if (m.count(cnt % n)) {
            break;
        } else {
            m[cnt % n] = make_pair(i, cnt);
            // cout << i << " " << cnt << endl;
        }
        // int index = cnt % n;
        // cout << "index : " << index << endl;
        cnt += a.at(cnt % n);
    }

    ll loop_size;
    ll loop_sum; 

    if (i != k) {
        loop_size = i-m.at(cnt % n).first;
        loop_sum = cnt - m.at(cnt % n).second;

        // cout << loop_size << " " << loop_sum << endl;

        cnt += ((k- i) / loop_size) * loop_sum;
        ll rem = k - i - ((k- i) / loop_size * loop_size);

        // cout << rem << endl;

        for (i = 0; i < rem; i++) {
            cnt += a.at(cnt % n);
        }
    }
    

    cout << cnt << endl;
    
    return 0;
}