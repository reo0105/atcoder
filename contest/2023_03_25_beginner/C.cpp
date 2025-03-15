#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    map<int, int> mp;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        mp[a]++;
    }

    int ans = 0;
    for (auto p : mp) {
        int x = p.first;
        int y = p.second;

        ans += y / 2;
    }

    cout << ans << endl;

    return 0;
}