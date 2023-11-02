#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;

    int ans = 0;
    int t = 1;
    int s = 1;

    for (int i = 0; i < a; i++) t *= b;
    for (int i = 0; i < b; i++) s *= a;
    cout << s+t << endl;

    return 0;
}