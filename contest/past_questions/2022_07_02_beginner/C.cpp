#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n, q;
    string s;
    cin >> n >> q >> s;

    int b = 0, e = n-1;

    for (int i = 0; i < q; i++) {
        int t, x;
        cin >> t >> x;
        if (t == 2) {
            int out = b + x - 1;
            if (out >= n) out -= n;
            cout << s.at(out) << '\n';
        } else {
            b -= x;
            if (b < 0) b += n;
            e = b-1;
            if (e < 0) e +- n;
        }
    }

    return 0;
}