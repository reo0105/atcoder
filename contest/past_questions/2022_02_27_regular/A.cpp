#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        if (s.at(i) != 'B') cout << s.at(i);
        else {
            if (i+1 < n && s.at(i+1) == 'B') {
                cout << 'A';
                i++;
            } else if (i+1 < n && s.at(i+1) == 'A') {
                cout << 'A';
                s.at(i+1) = 'B';
            } else {
                cout << s.at(i);
            }
        }
    } 

    cout << endl;

    return 0;
}