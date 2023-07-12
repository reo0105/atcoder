#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
    int n;
    cin >> n;

    int cnt = 0;
    ll ans = 0;
    vector<pi> ab;
    vector<int> a(200005), b(200005);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i) >> b.at(i);
        ab.push_back(make_pair(abs(a.at(i)-b.at(i)), i));
        if (a.at(i) > b.at(i)) cnt++;
        // cout << abs(a - b) << endl;
    }

    sort(ab.begin(), ab.end());

    if (cnt % 2) {
        int ng = ab.at(0).second;
        ans += (a.at(ng) > b.at(ng)) ? b.at(ng) : a.at(ng);
        for (int i = 0; i < n; i++) {
            if (i == ng) continue;
            ans += max(a.at(i), b.at(i));
        }
    } else {
        for (int i = 0; i < n; i++) {
            ans += max(a.at(i), b.at(i));
        }
    }

    cout << ans << endl;
    
    return 0;
}