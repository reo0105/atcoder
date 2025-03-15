#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int ok = 1;
    for (int i = 1; i <= 15; i += 2) {
        if (s[i] == '1') ok = 0;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}