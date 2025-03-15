#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string h, m;
    cin >> n;

    if (n >= 60) { h.append("22"); n -= 60; }
    else h.append("21");

    m.push_back('0' + n/10);
    m.push_back('0' + n % 10);

    cout << h << ":" << m << endl;

    return 0;
}