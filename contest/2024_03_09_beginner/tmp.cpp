#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    map<int, int> back;
    map<int, int> forward;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        int u = a[i];
        int v = a[i+1];

        back[v] = u;
        forward[u] = v;
    }

    forward[0] = a[0];
    back[1e9+5] = a[n-1];
    back[a[0]] = 0;
    forward[a[n-1]] = 1e9+5;

    int q;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int qi;
        cin >> qi;
        if (qi == 1) {
            int x, y;
            cin >> x >> y;
            int c = forward[x];
            int a = back[c];

            forward[a] = y;
            forward[y] = c;
            back[c] = y;
            back[y] = a;

        } else {
            int x;
            cin >> x;

            int a = back[x];
            int c = forward[x];

            back[c] = a;
            forward[a] = c;

        }
    }

    int now = 0;
    while (1) {
        now = forward[now];

        if (now == 1e9+5) break;

        cout << now << " ";
    }
    cout << endl;

    return 0;
}