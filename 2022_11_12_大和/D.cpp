#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, m;
    ll sum = 0;
    vector<int> a;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
        sum += a.at(i);
    }

    sort(a.begin(), a.end());

    // for (int i = 0; i < n; i++) cout << a.at(i);

    ll tmp = 0, num, ans = 1L << 58;
    bool cotinious = (((a.at(n-1)+1) % m) == a.at(0)) ? 1 : 0;
    
    // cout << ans << endl;

    int start = 0;
    tmp += a.at(0);

    for (int i = 0; i < n; i++) {
        num = a.at(i);
        if (i+1 < n && (a.at(i+1) == num || a.at(i+1) == num+1)) {
            tmp += a.at(i+1);
            // cout << tmp << endl;
        } else {
            if (ans > sum - tmp) {
                ans = sum - tmp;
                // cout << "ans " << ans << endl;
            }
            if (i+1 < n) {
                tmp = a.at(i+1);
                start = i+1;
            }
        }
    }

    // cout << start << endl;

    if (cotinious) {
        if (start == 0) cout << 0 << endl;
        else {
            for (int i = 0; i < n; i++) {
                num = a.at(i);
                if (i != start-1 && i+1 < n && (a.at(i+1) == num || a.at(i+1) == num+1)) {
                    tmp += a.at(i+1);
                } else {
                    if (ans > sum - tmp) {
                        ans = sum - tmp;
                    }
                    break;
                }
            }
            cout << ans << endl;
        }
    } else {
        cout << ans << endl;
    }

    return 0;
}