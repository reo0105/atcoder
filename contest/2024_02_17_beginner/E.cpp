#include <bits/stdc++.h>
using namespace std;

#include <atcoder/segtree>
using namespace atcoder;

int op(int a, int b) { return a+b; }
int e() { return 0; }

/*

s: 101010
A   11111
*/

int main()
{
    int n, q;
    string s;
    int x, l, r;

    cin >> n >> q >> s;

    segtree<int, op, e> seg(n+1);

    for (int i = 0; i < n-1; i++) {
        if (s[i] != s[i+1]) seg.set(i+1, 1);
    }

    for (int i = 0; i < q; i++) {
        cin >> x >> l >> r;
        if (x == 1) {
            seg.set(l-1, 1 - seg.get(l-1));
            seg.set(r, 1 - seg.get(r));
        } else {
            if (seg.prod(l, r) == (r-l)) cout << "Yes" << endl;
            else cout << "No" << endl; 
        }
    }

    return 0;
}