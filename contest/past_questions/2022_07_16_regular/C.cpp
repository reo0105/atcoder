#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> ans;
    set<int> rem;

    for (int i = 1; i <= n; i++) rem.insert(i);

    if (n < 2*k) cout << -1 << endl;
    else {
        for (int i = 1; i <= n; i++) {
            if (i + k > n - k) {
                ans.push_back(i+k);
                rem.erase(i+k);
            } else {
                int t;
                if (i > k) t = *rem.lower_bound(i+k);
                else t = *rem.lower_bound(1);
                ans.push_back(t);
                rem.erase(t);
            }
        }
    }

    for (int x : ans) cout << x << " ";
    cout << endl;

    return 0;
}