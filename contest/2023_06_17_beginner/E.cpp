#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
    int n, k, q;
    cin >> n >> k >> q;

    ll ans = 0;

    priority_queue<pi, vector<pi>, greater<pi>> calc;
    priority_queue<pi> que;
    map<int, int> mp;
    vector<int> a(500005, -1);
    set<int> inc;

    int i, si = 0;
    for (i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (a.at(x) == -1) {
            si++;
            a.at(x) = y;
            ans += y;
            inc.insert(x);
        } else {
            ans -= a.at(x);
            a.at(x) = y;
            ans += y;
        }
        cout << ans << endl;
        if (si == k) break;
    }

    for (int j = 1; j <= n; j++) {
        if (a.at(j) != -1) {
            calc.push(make_pair(a.at(j), j));
        }
    }

    for (i++; i < q; i++) {
        int x, y;
        cin >> x >> y;

        if (inc.count(x)) {
            int now = a.at(x);
            ans -= now;
            a.at(x) = y;
            // calcからも引きたい

            que.push(make_pair(y, x));
            inc.erase(x);
            pi maxi;
            while (1) {
                maxi = que.top();
                que.pop();
                if (a.at(maxi.second) == maxi.first) break;
            }
            ans += maxi.first;
            inc.insert(maxi.second);
            calc.push(make_pair(maxi.first, maxi.second));
        } else if (y > calc.top().first) {
            pi mini;
            while (1) {
                mini = calc.top();
                calc.pop();
                if (inc.count(mini.second)) break;
            }
            ans -= mini.first;
            inc.erase(mini.second);
            ans += y;
            inc.insert(x);
            calc.push(make_pair(y, x));
            a.at(x) = y;
            que.push(make_pair(mini.first, mini.second));
        } else {
            a.at(x) = y;
            que.push(make_pair(y, x));
        }

        cout << ans << endl;
    }

    return 0;
}