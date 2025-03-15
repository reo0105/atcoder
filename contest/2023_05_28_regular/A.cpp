#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> a;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.push_back(x);
    }

    sort(a.begin(), a.end());

    vector<int> ans(200005);

    int cnt = 0;
    for (int i = 0; i < n/2+1; i++) {
        ans.at(i*2) = a.at(cnt);
        cnt++;
    }

    for (int i = 0; i < n/2; i++) {
        ans.at(i*2+1) = a.at(cnt);
        cnt++;
    }

    // for (int i = 0; i < n; i++) {
    //     cout << ans.at(i) << " ";
    // }
    // cout << endl;

    int ok = 1;
    for (int i = 1; i < n; i+=2) {
        if (ans.at(i-1) < ans.at(i) && ans.at(i) > ans.at(i+1)) continue;
        ok = 0;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}