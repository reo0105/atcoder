#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int k;
    cin >> k;

    vector<ll> ans;

    ll num = 0;
    ll cnt = 1;
    for (int i = 1; i < (1<<10); i++) {
        num = 0;
        cnt = 1;
        for (int j = 0; j < 10; j++) {
            if (((i>>j) & 1) == 1) {
                num += cnt * j;
                cnt *= 10; 
            }
        }
        ans.push_back(num);
    }

    sort(ans.begin(), ans.end());
    cout << ans[k] << endl;

    return 0;
}