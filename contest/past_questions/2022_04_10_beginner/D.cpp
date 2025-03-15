#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;

int main()
{
    int q;

    cin >> q;

    queue<p> que;

    for (int i = 0; i < q; i++) {
        int n;
        cin >> n;

        if (n == 1) {
            ll x, c;
            cin >> x >> c;
            que.push(make_pair(x, c));
        } else {
            int c;
            ll sum = 0;
            cin >> c;
            
            while (c > 0) {
                p tmp = que.front();
                if (c >= tmp.second) {
                    que.pop();
                    sum += tmp.first * tmp.second;
                    c -= tmp.second;
                } else {
                    que.front().second -= c;
                    sum += tmp.first * c;
                    c = 0;
                }
            }

            cout << sum << endl;
        }
    }

    return 0;
}