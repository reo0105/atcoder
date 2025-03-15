#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    int ok = 0;
    for (int i = 0; i < n-1; i++) {
        if (s[i] == 'a' && s[i+1] == 'b') ok = 1;
        else if (s[i] == 'b' && s[i+1] == 'a') ok = 1;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}