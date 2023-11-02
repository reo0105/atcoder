#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;

    cin >> n >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (cnt == 0 && s[i] == 'A') cnt++;
        else if (cnt == 1 && s[i] == 'B') cnt++;
        else if (cnt == 2 && s[i] == 'C') cnt++;
        else if (s[i] == 'A') cnt = 1;
        else cnt = 0;

        // cout<< cnt << " ";
        if (cnt == 3) {
            cout << i-1 << endl;
            return 0;
        }
    }

    cout << -1 << endl;

    return 0;
}