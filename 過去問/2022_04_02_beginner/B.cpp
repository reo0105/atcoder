#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;

    cin >> a >> b;

    double x, y;
    double l = a*a + b*b;

    x = sqrt(l) * a / l;
    y = sqrt(l) * b / l;

    cout << fixed << setprecision(12) << x << " " << y << endl;

    return 0;
}