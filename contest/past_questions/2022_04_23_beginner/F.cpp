#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> t(200005), y(200005);

    for (int i = 0; i < n; i++) {
        cin >> t.at(i) >> y.at(i);
    }

    priority_queue<int> que;

    ll ans = -1e18;
    ll sum = 0;
    for (int i = n-1; i >= 0; i--) {
        if (t.at(i) == 1) {
            ans = max(ans, sum+y.at(i));
            k--;
            if (k < 0) break;
            if ((int)que.size() > k) {
                sum += que.top();
                que.pop();
            }
        } else if (t.at(i) == 2) {
            if (y.at(i) >= 0) {
                sum += y.at(i);
            } else {
                que.push(y.at(i));
                if ((int)que.size() > k) {
                    sum += que.top();
                    que.pop();
                }
            }
        }
    }

    ans = max(ans, sum);
    cout << ans << endl;

    return 0;
}