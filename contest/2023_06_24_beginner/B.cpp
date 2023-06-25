#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<string> s(105);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s.at(i);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            string t = s.at(i) + s.at(j);

            int si = (int)t.size();
            int ok = 1;
            for (int k = 0; k <= si/2; k++) {
                if (t.at(k) != t.at(si-k-1)) ok = 0;
            }

            if (ok) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl; 

    return 0;
}