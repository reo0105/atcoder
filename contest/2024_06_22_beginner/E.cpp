#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;

    ll ans = 0;
    ll maxi = 0;

    stack<pii> stk;
    stk.push(make_pair(0, 0));

    for (int i = 0; i < n; i++) {
        int h;
        cin >> h;

        int nw = 1;

        while (stk.size() && stk.top().first < h) {
            nw += stk.top().second;
            ans -= (ll)stk.top().first * stk.top().second;
            stk.pop();
        }

        ans += (ll)h * nw;
        stk.push(make_pair(h, nw));
        cout << ans+1 << " ";
    }
    cout << endl;

    return 0;
}