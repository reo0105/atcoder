#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v, a, b, c;
    int sum;

    cin >> v >> a >> b >> c;
    sum = a + b + c;

    v -= v/sum * sum;

    v-=a;
    if (v < 0) cout << "F" << endl;
    else if (v < 0) cout << "M" << endl;
    else cout << "T" << endl;

    return 0;
}