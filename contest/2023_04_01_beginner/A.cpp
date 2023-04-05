#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;

    int ok = 1;
    cin >> n >> s;

    for (int i = 0; i < n-1; i++) {
        if (s.at(i) == s.at(i+1)) ok = 0;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
} 