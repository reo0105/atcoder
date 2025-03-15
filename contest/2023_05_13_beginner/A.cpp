#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n;
    string s;
    int cntt = 0, cnta = 0;

    cin >> n;
    cin >> s;

    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'T') cntt++;
        else cnta++;
    }

    if (cntt == cnta) {
        for (int i = 0; i < n; i++) {
            if (s.at(i) == 'T') cntt--;
            else cnta--;

            if (cntt == 0) { cout << "T" << endl; return 0;}
            else if (cnta == 0) { cout << "A" << endl; return 0;}
        }
    }

    if (cntt > cnta) cout << "T" << endl;
    else cout << "A" << endl;

    return 0;
}