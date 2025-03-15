#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    vector<int> a(n);
    map<int, int> to;
    map<int, int> inv;

    for (int i = 0; i < n; i++) cin >> a[i];

    int start = a[0];

    for (int i = 0; i < n-1; i++) to[a[i]] = a[i+1];
    for (int i = 0; i < n-1; i++) inv[a[i+1]] = a[i];

    to[a[n-1]] = -1;
    inv[a[0]] = -1;

    int q;
    cin >> q;

    for (int i = 0; i < q; i++) {
        int qi;
        cin >> qi;

        if (qi == 1) {
            int x, y;
            cin >> x >> y;

            int t = to[x];
            to[x] = y;
            to[y] = t;

            t = to[y];
            inv[t] = y;
            inv[y] = x;
        } else {
            int x;
            cin >> x;

            int prev = inv[x];
            int forg = to[x];

            to[prev] = forg;
            inv[forg] = prev;

            if (x == start) start = forg;
        }
    }

    int now = start;
    int end;

    while (now != -1) {
        cout << now << " ";
        now = to[now];
        if (now !=-1) end = now;
    }

    cout << endl;
    return 0;
}