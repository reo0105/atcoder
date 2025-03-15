#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    string s;
    cin >> s;

    vector<int> cnt(26, 0);

    ll ans = 0;
    int same = 0;

    for (int i = 0; i < (int)s.size(); i++) {
        ans += i;
        ans -= cnt[s[i] - 'a'];

        if (cnt[s[i] - 'a'] != 0) same = 1;
        cnt[s[i] - 'a']++;
    }

    cout << ans+same << endl;

    return 0;
}