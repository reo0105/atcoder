#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, count = 0, ds = 0, dt = 0, tmp;
    string s, t, u;
    set<int> indec;

    cin >> n;
    cin >> s >> t;

    tmp = n - 1;

    for(int i = 0; i < n; i++) {
        if (s.at(i) != t.at(i)) count++;
        else indec.insert(i);
    }

    if (count%2 == 1) {
        cout << -1 << endl;
    } else {
        u.assign(n, '0');
        for (int i = 0; i < n; i++) {
            if (s.at(i) != u.at(i)) ds++;
            if (t.at(i) != u.at(i)) dt++;
        }

        while(ds != dt) {
            if(!indec.count(tmp)) {
                if (ds < dt) {
                    if (s.at(tmp) == u.at(tmp) && s.at(tmp) == '0') {
                        u.at(tmp) = '1';
                        ds++;
                        dt--;
                    }
                } else {
                    if (t.at(tmp) == u.at(tmp) && t.at(tmp) == '0') {
                        u.at(tmp) = '1';
                        dt++;
                        ds--;
                    }
                }
            }
            
            tmp--;

            if (ds != dt && tmp == -1) {
                cout << -1 << endl;
                goto end;
            }
        }

        cout << u << endl;
    }
end:
    return 0;
}