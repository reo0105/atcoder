#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    map<int, int> mp;

    for (int i = 0; i < n; i++) {
        int a, c;
        cin >> a >> c;

        if (mp[c] == 0) mp[c] = a;
        else mp[c] = min(mp[c], a);
    }

    int ans = 0;
    for (auto [a, c] : mp) {
        ans = max(ans, c);
    }

    cout << ans << endl;

    return 0;
}