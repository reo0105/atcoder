#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n;
    string t;
    set<p> s;

    cin >> n;
    cin >> t;

    int x = 0, y = 0;
    int flag = 0;

    s.insert(make_pair(x, y));

    for (int i = 0; i < n; i++) {
        if(t.at(i) == 'R') x++;
        else if (t.at(i) == 'L') x--;
        else if (t.at(i) == 'U') y++;
        else y--;

        if (s.count(make_pair(x, y))) {
            flag = 1;
            break;
        }

        s.insert(make_pair(x, y));
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}