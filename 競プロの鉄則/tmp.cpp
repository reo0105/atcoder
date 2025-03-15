#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    vector<int> a(100002);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a.at(i);

    ll ans = 0;
    int right = 0;
    for (int left = 0; left < n; left++) {

        while (right+1 < n && a.at(right+1) - a.at(left) <= k) {
            right++;
        }

        ans += right - left;

        if (left == right) right++;
    }

    cout << ans << endl;

    return 0;
}