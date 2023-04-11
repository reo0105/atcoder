#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

/*
何個シャッフルするのが最適かいまいちわからない
*/

int main()
{
    int n;
    vector<int> a;
    vector<p> as;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
        as.push_back(make_pair(x, i));
    }

    int mid = n / 2 - 1;
    // sort(a.begin(), a.end());
    sort(as.rbegin(), as.rend());

    vector<int> b(n+1);

    int cnt = 0;
    for (p x : as) {
        if (cnt <= mid) {
            b.at(x.second) = 1;
        } else {
            b.at(x.second) = -1;
        }
        cnt++;
    }

    for (int i = 0; i < n-1; i++) {
        b.at(i+1) += b.at(i);
    }

    // for (int i = 0; i < n; i++) {
    //     cout << b.at(i) << " ";
    // }
    // cout << endl;

    int maxi = 0, index = 0;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (b.at(i) == 1) {
            if (maxi < cnt) {
                maxi = cnt;
                index = i;
            }
            cnt = 0;
        } else {
            cnt++;
        }
    }

    maxi = max(cnt, maxi);
    
    // int maxi = 0;
    // for (int i = 0; i < n; i++) {
    //     maxi = min(maxi, b.at(i));
    // }

    // vector<int> c(n+1);
    // for (int i = 0; i < n; i++) {
    //     c.at(i+1) = c.at(i) + b.at(i+1);
    //     mini = min(mini, c.at(i+1));
    // }

    ll sum = 0;
    for (int i = 0; i < mid+1; i++) sum += as.at(i).first;

    // cout << maxi << " " << index << endl;
    maxi += index - maxi;
    cout << maxi % n << " " << sum << endl; 

    return 0;
}