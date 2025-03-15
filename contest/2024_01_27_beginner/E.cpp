#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    map<int, int> mp;
    cin >> n;

    for (int i = 1; i <= n; i++) {
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x, y);
        mp[x] = i;
        mp[y] = i + n;
    }

    int ok = 0;
    stack<int> stk;

    for (int i = 1; i <= 2*n; i++) {
        int val = mp[i];

        if (val > n) {
            int top = stk.top();
            stk.pop();

            if (val-n != top) {
                ok = 1;
                break;
            }
        } else {
            stk.push(mp[i]);
        }
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}