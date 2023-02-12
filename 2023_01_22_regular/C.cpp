#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    vector<int> a(5005), b(5005);

    for (int i = 0; i < t; i++) {
        int n;
        set<int> x, y;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a.at(i);
            x.insert(a.at(i));
        }
        a.at(n) = a.at(0);
        for (int i = 0; i < n; i++) {
            cin >> b.at(i);
            y.insert(b.at(i));
        }
        int flag=  1;
        for (auto n : y) {
            if (!x.count(n)) { flag = 0; break; }
        }
        if ((int)y.size() == n) flag = 0;

        if (flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}