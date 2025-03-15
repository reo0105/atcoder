#include <bits/stdc++.h>
#include <atcoder/fenwicktree>
using namespace std;
using namespace atcoder;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;

int main()
{
    int n, m;
    cin >> n >> m;

    fenwick_tree<ll> fw(n+1);

    int pre = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        fw.add(i, a-pre);
        pre = a;
    }

    for (int i = 0; i < m; i++) {
        int b;
        cin >> b;

        ll now = fw.sum(0, b+1);

        fw.add(b, -now);
        fw.add(b+1, now);

        ll loop = now / n;
        ll rem = now % n;

        fw.add(0, loop);

        if (rem + b >= n) {
            fw.add(b+1, 1);
            fw.add(0, 1);
            fw.add(rem+b+1-n, -1);
        } else {
            fw.add(b+1, 1);
            fw.add(b+1+rem, -1);
        }
    }

    for (int i = 0; i < n; i++) cout << fw.sum(0, i+1) << " ";
    cout << endl;


    return 0;
}