#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, x;
    cin >> a >> b >> c >> x;

    if (x <= a) cout << 1 << endl;
    else if (x <= b) cout << fixed << setprecision(12) << (double)c / (b-a) << endl; 
    else cout << 0 << endl;

    return 0;
}