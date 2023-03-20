#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

/*
二分探索だけど境界で満たす満たさないが変わるような単純なものじゃないから
実装にちょっと手間がかかった。
*/

int main()
{
    int n;
    cin >> n;

    int x, y;
    int l = 1, r = n+1;

    while (r - l > 1) {
        int mid = (l+r) / 2;
        int t;

        cout << "? " << l  << " " << mid-1 << " " << 1 << " " << n << endl;
        cin >> t;

        if (t == mid-l) l = mid;
        else r = mid;
    }

    x = l;
    l = 1, r = n+1;

    while (r - l > 1) {
        int mid = (l+r) / 2;
        int t;

        cout << "? " << 1 << " " << n << " " << l << " " << mid-1 << endl;
        cin >> t;

        if (t == mid-l) l = mid;
        else r = mid;
    }

    y = l;

    cout << "! " << x << " " << y << endl;

    return 0;
}