#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    string s;
    cin >> s;
    int n = (int)s.size();

    vector<int> cnt(1050, 0);

    int now = 0;
    cnt.at(0)++;
    for (int i = 1; i <= n; i++) {
        int x = s.at(i-1) - '0';
        now ^= (1<<x);
        cnt.at(now)++;
    }

    ll ans = 0;

    for (int i = 0; i < (1<<10); i++) {
        // cout << cnt.at(i) << " ";
        ans += (ll)cnt.at(i) * (cnt.at(i) - 1) / 2;
    }

    cout << ans << endl;   
    

    return 0;
}