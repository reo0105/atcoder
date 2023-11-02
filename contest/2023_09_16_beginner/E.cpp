#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<ll> ans(200005, 0);
    set<pii> ms;
    set<int> row;

    for (int i = 1; i <= n; i++) row.insert(i);
    
    for (int i = 0; i < m; i++) {
        int t, w, s;
        cin >> t >> w >> s;
        
        if (ms.size()) {
            while(1) {
                pii mini = *begin(ms);
                if (mini.first <= t) {
                    ms.erase(mini);
                    row.insert(mini.second);
                } else {
                    break;
                }
                if ((int)ms.size() == 0) break;
            }
        }
        
        if (row.size()) {
            int p = *begin(row);
            row.erase(p);
            ans[p] += w;
            ms.insert(make_pair(t+s, p));
        }

    }

    for (int i = 1; i <= n; i++) cout << ans[i] << endl;
}