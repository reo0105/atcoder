#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll x, k, count = 10, tmp;

    cin >> x >> k;

    for (int i = 0; i < k; i++) {
        tmp = x % count;
        x -= tmp;
        
        if (tmp >= 5 * count / 10) {
            x += count;
        }

        count *= 10;

    }

    cout << x << endl;

    return 0;
}