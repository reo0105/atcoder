#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    ll ans = 0;
    int now = 0;
    int cnt = 0;

    for (int i = 0; i < n-1; i++) {
        if (s[i] == '>') cnt++;
        else if (s[i] == '<') {
            ans += (ll)cnt * (cnt+1) / 2;
            cnt = 0;
        }
    }
    ans += (ll)cnt * (cnt+1) / 2;

    cout << ans << endl;


    return 0;
}