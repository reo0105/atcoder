#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    vector<int> c(12);
    vector<vector<int>> a(12, vector<int>(12));

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> c.at(i);
        for (int j = 0; j < c.at(i); j++) {
            cin >> a.at(i).at(j);
        }
    }

    int ans = 0;
    set<int> st;
    for (int s = 1; s < (1<<m); s++) {
        for (int i = 0; i < m; i++) {
            if (((s>>i) & 1) == 0) continue;

            for (int j = 0; j < c.at(i); j++) {
                st.insert(a.at(i).at(j));
            }
        }

        if ((int)st.size() == n) ans++;
        st.clear();
    }
    cout << ans << endl;

    return 0;
}