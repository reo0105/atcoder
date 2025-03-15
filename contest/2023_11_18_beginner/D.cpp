#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, int> mp;
    set<pii> st;

    for (int i = 0; i < m; i++) {
        int a;
        cin >> a;

        int now = mp[a];
        mp[a]++;

        // cout << now << " ";

        if (now != 0) st.erase(make_pair(now, -a));
        st.insert(make_pair(now+1, -a));

        pii maxi = *rbegin(st);

        cout << -maxi.second << endl;      
    }

    return 0;
}