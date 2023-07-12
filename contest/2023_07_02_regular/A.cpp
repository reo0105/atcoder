#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        int n;
        string s;
        cin >> n >> s;

        int ok = 0;
        string s0;
        s0.push_back(s.at(0));
        for (int i = 1; i < n; i++) {
            if (s0.at(0) < s.at(i)) {
                ok = 1;
                break;
            } else if (s0.at(0) == s.at(i)) {
                int j;
                for (j = 1; j < (int)s0.size(); j++) {
                    if (i+j < n && s0.at(j) < s.at(i+j)) {
                        ok = 1;
                        break;
                    } else if (i+j < n && s0.at(j) > s.at(i+j)) break;
                }
                if (j == (int)s0.size() && (int)s0.size()*2 < n) ok = 1;
                if (ok) break;
            } else if (s0.at(0) > s.at(i)) {
                s0.push_back(s.at(i));
            }
        }

        if (ok) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}