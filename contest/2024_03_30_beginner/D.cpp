#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll a, b, c;
    cin >> a >> b >> c;

    vector<int> k(62, 0);

    int cnt = 0;
    while (c > 0) {
        if (c & 1) k[cnt] = 1;
        c >>= 1;
        cnt++;
    }

    ll x = 0, y = 0;
    
    ll two = 1;
    for (int i = 0; i < 62; i++) {
        if (k[i]) {
            if (a > b) {
                x += two;
                a--;
            } else {
                y += two;
                b--;
            }
        }
        two <<= 1;
    }

    if (a != b) {
        cout << -1 << endl;
    } else {
        two = 1;
        for (int i = 0; i < 62; i++) {
            if (!k[i] && a != 0) {
                x += two;
                y += two;
                a--;
            }
            two <<= 1;
        }
        if (a == 0) cout << x << " " << y << endl;
        else cout << -1 << endl;
    }
    
}