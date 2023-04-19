#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int ok = 0, ng = 0;

    for (int i = 0; i < n; i++) {
        if(s.at(i) == 'o') ok++;
        else if (s.at(i) == 'x') ng++;
    }

    if (ok >= 1 && ng == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}