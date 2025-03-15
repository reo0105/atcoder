#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    map<int, int> a, b;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (a.count(x)) a.at(x)++;
        else a[x] = 1;
    }

    int i;
    for (i = 0; i < m; i++) {
        int x;
        cin >> x;
        if (a.count(x) && a.at(x) != 0) a.at(x)--;
        else break;
    }

    if (i == m) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}