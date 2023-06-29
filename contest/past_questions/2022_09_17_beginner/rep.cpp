#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;

int main()
{
    int n;
    cin >> n;

    int a = 1, b = n;
    int c = 1, d = n;
    int x, y;

    while (b-a > 0) {
        int mid = (a+b) / 2;

        cout << "? " << a << " " << mid << " " << c << " " << d << endl;
        int t;
        cin >> t;
        if (t == -1) return -1;

        if (t == mid-a+1) { a = mid+1; x = a; }
        else { b = mid; x = b; }
    }

    // cout << x << endl;

    while (d-c > 0) {
        int mid = (c+d) / 2;

        cout << "? " << 1 << " " << n << " " << c << " " << mid << endl;
        int t;
        cin >> t;
        if (t == -1) return -1;

        if (t == mid-c+1) { c = mid+1; y = c; }
        else { d = mid; y = d; }
    }

    cout << "! "  << x << " " << y << endl;
}