#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n, m, h, k;
    cin >> n >> m >> h >> k;
    string s;
    set<p> st;

    cin >> s;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        st.insert(make_pair(x, y));
    }

    int x = 0, y = 0;
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'R') x++;
        else if (s.at(i) == 'L') x--;
        else if(s.at(i) == 'U') y++;
        else if (s.at(i) == 'D') y--;

        h--;
        if (h < 0) break;

        if (h < k && st.count(make_pair(x, y))) {
            h = k;
            st.erase(make_pair(x, y));
        }

        if (i == n-1) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
}