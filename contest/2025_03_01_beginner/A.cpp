#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    bool ok = true;
    int pre;
    cin >> pre;

    for (int i = 0; i < n-1; i++) {
        int a;
        cin >> a;
        if (pre >= a) ok = false;
        swap(a, pre);
    }

    if (ok)cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}