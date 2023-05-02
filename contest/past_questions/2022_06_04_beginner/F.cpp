#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

int op(int x, int y) {
    return gcd(x, y);
}

int e() {
    return 0;
}

int main()
{
    int n, q;
    cin >> n >> q;
    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++) cin >> a.at(i);
    for (int i = 0; i < n; i++) cin >> b.at(i);

    segtree<int, op, e> ta(n), tb(n);

    for (int i = 0; i < n-1; i++) ta.set(i, a.at(i+1)-a.at(i));
    for (int i = 0; i < n-1; i++) tb.set(i, b.at(i+1)-b.at(i));

    for (int i = 0; i < q; i++) {
        int h1, h2, w1, w2;
        cin >> h1 >> h2 >> w1 >> w2;
        h1--; w1--;

        int ans = a.at(h1) + b.at(w1);
        ans = gcd(ans, ta.prod(h1, h2-1));
        ans = gcd(ans, tb.prod(w1, w2-1));
        cout << ans << endl;
    }

    return 0;
}