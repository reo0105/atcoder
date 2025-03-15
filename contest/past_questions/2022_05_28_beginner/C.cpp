#include <bits/stdc++.h>
using namespace std;

int main()
{
    int q;
    map<int, int> m;
    set<int> s;
    cin >> q;
    
    for (int i = 0; i < q; i++) {
        int t;
        cin >> t;
        if (t == 1) {
            int x;
            cin >> x;
            m[x]++;
            s.insert(x);
        } else if (t == 2) {
            int x, c;
            cin >> x >> c;
            int num = min(c, m[x]);
            if (m[x] > num) m[x] -= num;
            else { m[x] = 0; s.erase(x); }
        } else {
            cout << *rbegin(s) - *begin(s) << endl;
        }
    }

    return 0;
}