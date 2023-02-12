#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p; 

int main()
{
    int x1, y1, x2, y2;
    vector<int> dir_x = {2, 1, -1, -2, -2, -1, 1, 2};
    vector<int> dir_y = {1, 2, 2, 1, -1, -2, -2, -1};
    set<p> s;

    cin >> x1 >> y1 >> x2 >> y2;

    int i;
    for (i = 0; i < 8; i++) {
        int new_x = x1 + dir_x.at(i);
        int new_y = y1 + dir_y.at(i);
        s.insert(make_pair(new_x, new_y));
    }

    for (i = 0; i < 8; i++) {
        int new_x = x2 + dir_x.at(i);
        int new_y = y2 + dir_y.at(i);
        if (s.count(make_pair(new_x, new_y))) break;
    }

    if (i == 8) cout << "No" << endl;
    else cout << "Yes" << endl;

    return 0;
}