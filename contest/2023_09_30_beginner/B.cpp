#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    string s, t;

    cin >> n >> m;
    cin >> s >> t;


    int cnt0 = 0;
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == t[i]) cnt0++;
        else break;
    }

    for (int i = 0; i < n; i++) {
        if (s[i] == t[m-n+i]) cnt1++;
        else break;
    }

    if (cnt0 == n && cnt1 == n) cout << 0 << endl;
    else if (cnt0 == n && cnt1 != n) cout << 1 << endl;
    else if (cnt0 != n && cnt1 == n) cout << 2 << endl;
    else cout << 3 << endl;

    return 0;
}