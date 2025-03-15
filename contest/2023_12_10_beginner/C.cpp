#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    string s;
    cin >> s;

    int ans = 0;
    int ok = m;
    int muji = m;
    int logo = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == '0') {
            logo = ans;
            muji = m;
        } else if (s[i] == '1') {
            if (muji > 0) {
                muji--;
            } else if (logo != 0) {
                logo--;
            } else {
                ans++;
            }
        } else {
            if (logo != 0) {
                logo--;
            } else {
                ans++;
            }
        }
    }

    cout << ans << endl;

    return 0;
}