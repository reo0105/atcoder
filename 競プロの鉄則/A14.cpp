#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k, flag = 0;
    vector<int> a(1002), b(1002), c(1002), d(1002);
    vector<int> p(1000002), q(1000002);

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> a.at(i);
    for (int i = 0; i < n; i++) cin >> b.at(i);
    for (int i = 0; i < n; i++) cin >> c.at(i);
    for (int i = 0; i < n; i++) cin >> d.at(i);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            p.at(i*n+j) = a.at(i) + b.at(j);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            q.at(i*n+j) = c.at(i) + d.at(j);
        }
    }

    sort(q.begin(), q.end());

    for (int i = 0; i < n*n; i++) {
        int re = *lower_bound(q.begin(), q.end(), k-p.at(i));
        if (re == k-p.at(i)) {
            flag = 1;
            break;
        }

    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}