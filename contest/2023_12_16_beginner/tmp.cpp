#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> t(n), x(n);

    for (int i = 0; i < n; i++) {
        cin >> t[i] >> x[i];
        x[i]--;
    }

    int need = 0;
    int k = 0;
    vector<int> ans;
    vector<int> portion(n, 0);
    for (int i = n-1; i >= 0; i--) {
        if (t[i] == 1) {
            if (portion[x[i]] == 0) {
                ans.push_back(0);
            } else {
                portion[x[i]]--;
                need--;
                ans.push_back(1);
            }
        } else {
            portion[x[i]]++;
            need++;
            k = max(k, need);
        }
    }

    int ok = 1;
    for (int i = 0; i < n; i++) {
        if (portion[i] != 0) ok = 0;
    }

    if (!ok) cout << -1 << endl;
    else {
        cout << k << endl;
        reverse(ans.begin(), ans.end());
        for (int x : ans) cout << x << " ";
        cout << endl;
    }

    return 0;
}