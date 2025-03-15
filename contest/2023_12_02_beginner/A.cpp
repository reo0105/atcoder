#include <bits/stdc++.h>
using namespace std;

int main()
{
    int M, D;
    int y, m, d;
    cin >> M >> D;
    cin >> y >> m >> d;

    d++;
    if (d > D) { m++; d = 1; }
    if (m > M) { y++; m = 1; }

    cout << y << " " << m << " " << d << endl;

    return 0;
}