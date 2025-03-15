#include <bits/stdc++.h>
using namespace std;
#include <atcoder/fenwicktree>
using namespace atcoder;

typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    fenwick_tree<ll> fw(n+1);
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw.add(i, a);
        fw.add(i+1, -a);
    }

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;

        ll x = fw.sum(0, b+1);

        fw.add(b, -x);
        fw.add(b+1, x);

        ll c = x / n;
        x %= n;

        b++;

        fw.add(0, c);
        fw.add(n, -c);

        if (b+x < n) {
            fw.add(b, 1);
            fw.add(b+x, -1);
        } else {
            fw.add(b, 1);
            fw.add(n, -1);
            fw.add(0, 1);
            fw.add(b+x-n, -1);
        }
    }

    for (int i = 0; i < n; i++) {
        cout << fw.sum(0, i+1) << " ";
    }
    cout << endl;


    return 0;
}