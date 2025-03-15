#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    map<int, int> mp;
    char now = s[0];
    int cnt = 1;

    for (int i = 1; i < n; i++) {
        if (now == s[i]) cnt++;
        else {
            mp[now-'a'] = max(mp[now-'a'], cnt);
            cnt = 1;
            now = s[i];
        }
    }

    mp[now-'a'] = max(mp[now-'a'], cnt);

    int ans = 0;
    for (int i = 0; i < 26; i++) { ans += mp[i]; }

    cout << ans << endl;

    return 0;
}