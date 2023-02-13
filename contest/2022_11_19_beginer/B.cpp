#include <bits/stdc++.h>
using namespace std;

int main()
{
    int h, m;
    int a, b, c, d;

    cin >> h >> m;

    a = h / 10;
    b = h % 10;
    c = m / 10;
    d = m % 10;

    while (1) {
        swap(b, c);
        if (a == 2 && 0 <= b && b <= 3 && 0 <= c && c <= 5) break;
        if (a != 2 && 0 <= b && b <= 9 && 0 <= c && c <= 5) break;

        m++;
        if (m == 60) {
            h++;
            m = 0;
        }

        if (h == 24) {
            h = 0;
        }

        a = h / 10;
        b = h % 10;
        c = m / 10;
        d = m % 10;
    }

    swap(b, c);
    cout << a << b << " " << c << d << endl;

    return 0;
}