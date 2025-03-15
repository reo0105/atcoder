#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> a(200005);
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    for (int i = 1; i <= n; i++) a.at(i) %= (x+y);
    

    if (x < y) {
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (x <= a.at(i) && a.at(i) < y) flag = 1;
        }

        if (flag) cout << "First" << endl;
        else {
            for (int i = 1; i <= n; i++) {
                if (a.at(i) >= y) flag = 1;
            }
            if (!flag) cout << "Second" << endl;
            else cout << "First" << endl;
        }
    } else if (x == y) {
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (x <= a.at(i)) flag = 1;
        }

        if (flag) cout << "First" << endl;
        else cout << "Second" << endl;
    } else {
        int flag = 0;
        for (int i = 1; i <= n; i++) {
            if (y <= a.at(i) && a.at(i) < x) flag = 1;
        }

        if (flag) cout << "Second" << endl;
        else {
            for (int i = 1; i <= n; i++) {
                if (a.at(i) >= x) flag = 1;
            }
            if (!flag) cout << "First" << endl;
            else cout << "Second" << endl;
        }
    }
}