#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int ok = 1;
    int a;

    cin >> a;
    for (int i = 1; i < n; i++) {
        int b;
        cin >> b;
        if (a != b) ok = 0;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}