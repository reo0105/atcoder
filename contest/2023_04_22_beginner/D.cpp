#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int l = 1, r = n;
    while (r - l > 1) {
        int mid = (l+r) / 2;
        int ret;
        cout << "? " << mid << endl;
        cin >> ret;

        if (ret == 0) l = mid;
        else r = mid;
    }

    cout << "! " << l << endl;

    return 0;
}