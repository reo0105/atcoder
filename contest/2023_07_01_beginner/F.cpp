#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> p;
    vector<pi> ld;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        p.push_back(x);
    }

    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        ld.push_back(make_pair(x, 0));
    }

    for (int i = 0; i < m; i++) {
        cin >> ld.at(i).second;
    }

    sort(p.begin(), p.end());
    sort(ld.begin(), ld.end());

    ll ans = 0, id = 0;
    multiset<int> ms;
    for (int i = 0; i < n; i++) {
        int c = p.at(i);

        while (id < m && ld.at(id).first <= c) {
            ms.insert(ld.at(id).second);
            id++;
        }

        if (ms.size()) {
            int maxi = *rbegin(ms);
            ans += p.at(i) - maxi;
            ms.erase(ms.find(maxi));
        } else {
            ans += p.at(i);
        }

        // cout << ans << " ";
    }
    // cout << endl;
    
    cout << ans << endl;

    return 0; 
}