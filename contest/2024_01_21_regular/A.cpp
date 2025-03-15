#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s, t;
    cin >> n >> s >> t;

    int fa = n, lb = -1;

    for (int i = 0; i < n; i++) {
        if (fa == n && s[i] == 'A') fa = i;
        else if (s[i] == 'B') lb = i;
    }

    int ans = 0;
    deque<int> as, bs;

    for (int i = 0; i < n; i++) {
        if (s[i] != t[i] && s[i] == 'B') as.push_back(i);
        else if (s[i] != t[i] && s[i] == 'A') bs.push_back(i);
    }

    while (as.size()) {
        int a = as.front();
        as.pop_front();

        int b;
        if (bs.size()) {
            int cnt = 0;
            while (cnt < (int)bs.size()) {
                b = bs.front();
                bs.pop_front();

                if (a < b) break;
                else {
                    cnt++;
                    bs.push_back(b);
                    if (cnt == (int)bs.size()) b = lb;
                }
            }

        } else {
            b = lb;
        }

        if (a < b) {
            ans++;
            fa = min(fa, a);
            lb = max(lb, b);
        } else {
            ans = 1e9;
            break;
        }
    }

    while (bs.size()) {
        int a = fa;

        int b = bs.front();
        bs.pop_front();

        if (a < b) ans++;
        else {
            ans = 1e9;
            break;
        }
    }

    if (ans >= 1e9) ans = -1;
    cout << ans << endl;

    return 0;
}