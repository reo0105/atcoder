#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >>  s;

    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'n') {
            if (i+1 < n && s.at(i+1) == 'a') {
                cout << "nya";
                i++;
            } else {
                cout << 'n';
            }
        } else {
            cout << s.at(i);
        }
    }
    cout << endl;

    return 0;
}