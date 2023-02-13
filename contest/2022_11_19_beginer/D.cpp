#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, q, pre = -1;
    vector<ll> a(200002);
    queue<int> queue;
    set <int> s;


    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        int que, index;
        ll x;
        cin >> que;
        if (que == 1) {
            cin >> x;
            pre = x;
            while(!queue.empty()) {
                int t = queue.front();
                queue.pop();
                if (s.count(t)) s.erase(t);
            }
        } else if (que == 2) {
            cin >> index >> x;
            if (pre != -1 && !s.count(index)) {
                a.at(index) = pre;
                s.insert(index);
                queue.push(index);
            }
            a.at(index) += x;
        } else {
            cin >> index;
            if (pre != -1 && !s.count(index)) {
                a.at(index) = pre;
                s.insert(index);
                queue.push(index);
            }
            cout << a.at(index) << endl;
        }
    }

    return 0;
}