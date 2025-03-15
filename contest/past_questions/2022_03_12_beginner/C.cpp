#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n;
    // vector<int> p(200005);
    set<int> s;
    map<int, vector<p>> m;
    string str;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        s.insert(y);
        m[y].push_back(make_pair(x, i));
    }


    cin >> str;

    int flag = 0;

    while(!s.empty()) {
        int y = *begin(s);
        s.erase(y);

        sort(m[y].begin(), m[y].end());
        int dir = -1;
        for (int i = 0; i < (int)m[y].size(); i++) {
            int j = m[y].at(i).second;
            if (dir == -1 && str.at(j) == 'R') dir = 0;
            if (dir == 0 && str.at(j) == 'L') dir = 1;
        }

        if (dir == 1) {
            flag = 1;
            break;
        }
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl; 

    return 0;
}