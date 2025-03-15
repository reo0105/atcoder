#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, maxi = 0;
    string s;
    vector<int> child, adult;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        if (s.at(i) == '0') { child.push_back(w); maxi = max(maxi, w); }
        else adult.push_back(w);
    } 

    child.push_back(maxi+1);
    sort(child.begin(), child.end());
    sort(adult.begin(), adult.end());

    int ans = 0;
    int si = (int)child.size();
    auto end = adult.end();
    auto beg = child.begin();
    for (int i = 0; i < si; i++) {
        int thr = child.at(i);
        int t0 = end - lower_bound(adult.begin(), adult.end(), thr);
        int t1 = lower_bound(child.begin(), child.end(), thr) - beg;
        ans = max(ans, t0+t1);
        // cout << t0 << t1 << endl;
    }


    // cout << ans << endl;

    si = (int)adult.size();
    for (int i = 0; i < si; i++) {
        int thr = adult.at(i);
        int t0 = end - lower_bound(adult.begin(), adult.end(), thr);
        int t1 = lower_bound(child.begin(), child.end(), thr) - beg;
        if (t1 > 0) t1--;
        ans = max(ans, t0+t1);
        // cout << t0 << t1 << endl;
    }

    cout << ans << endl;

    return 0;
}