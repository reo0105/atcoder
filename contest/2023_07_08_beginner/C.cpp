#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    ll now = 0;
    int ans = 0;

    vector<pi> ab(n);
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        ab.at(i) = make_pair(a, b);
        now += b;
    }

    sort(ab.begin(), ab.end());

    for (int i = 0; i < n; i++) {
        if (now <= k) {
            cout << ans+1 << endl;
            return 0;
        }
        now -= ab.at(i).second;
        ans = ab.at(i).first;
    }

    cout << ans+1 << endl;
    return 0;
}