#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if (a % k == 0) cout << a / k << " ";
    }

    cout << endl;

    return 0;
}