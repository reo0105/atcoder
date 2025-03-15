#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, l;
    vector<int> a;

    cin >> n >> l;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    // int right = 1;
    // int sum = a.at(1), t = l;
    // for (int left = 1; left <= n; left++) {
    //     while (right <= n && abs(sum + a.at(right) - l) < t) {
    //         t = abs(sum + a.at(right) - l);
    //         right++;
    //     }

    //     if (left == n) break;

    //     if (right == left) right++;
    //     else sum = a.at(left+1);
    // }

    ll t = 2*l, ans = 2*l;
    for (int i = 0; i < n; i++) {
        int x = a.at(i);
        int index = lower_bound(a.begin(), a.end(), l-x) - a.begin();
        if (index < n) {
            int y = a.at(index);
            t = max(x+y, 2*l-x-y);
            if (t < ans) ans = t;
        }
        if (index > 0) {
            int y = a.at(index-1);
            t = max(x+y, 2*l-x-y);
            if (t < ans) ans = t;
        }
    }

    cout << 2*ans << endl;

    return 0;
}