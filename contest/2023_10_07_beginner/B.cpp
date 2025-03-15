#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    
    int n;
    cin >> n;

    vector<pii> ans(n, make_pair(0, 0));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ans[i].second = -i;
        for (int j = i+1; j < n; j++) {
            if (s[j] == 'o') ans[i].first++;
            else ans[j].first++;
        }
    }

    sort(ans.rbegin(), ans.rend());

    for (int i = 0; i < n; i++) {
        cout << -ans[i].second + 1 << " ";
    }
    cout << endl;

    return 0;
}