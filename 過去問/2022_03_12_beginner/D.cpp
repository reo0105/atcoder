#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, x;
    string s;

    cin >> n >> x;
    cin >> s;

    deque<int> que;

    ll lim = 1L;
    for (int i = 1; i <= 60; i++) {
        if (lim<<i > x) break;
        if ((x >> (i-1)) & 1) que.push_front(1);
        else que.push_front(0);
    }

    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'L') {
            que.push_back(0);
        } else if (s.at(i) == 'R') {
            que.push_back(1);
        } else {
            que.pop_back();
        }
    }

    ll ans = 1;
    while(!que.empty()) {
        int n = que.front();
        que.pop_front();
        ans <<= 1;
        if (n == 1) ans++;
    }

    cout << ans << endl;

    return 0;
}