#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int n = 8;

    int cnt = 0;
    int fir;
    int flag0 = 0;
    for (int i = 0; i < n; i++) {
        if (cnt == 0 && s.at(i) == 'B') { fir = i; cnt++; }
        else if (cnt == 1 && s.at(i) == 'B') {
            // cout << fir << " " << i << endl;
            if (fir % 2 != i % 2) flag0 = 1;
        }
    }

    int flag1 = 0;
    cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt == 0 && s.at(i) == 'R') cnt++;
        else if (cnt == 1 && s.at(i) == 'K') cnt++;
        else if (cnt == 2 && s.at(i) == 'R') cnt++;
    }

    if (flag0 && cnt == 3) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}