#include <bits/stdc++.h>
using namespace std;

int f(int x)
{
    return x * x + 2 * x + 3;
}

int main()
{
    int t, ans = 1;

    cin >> t;

    cout << f(f(f(t) + t) + f(f(t))) << endl;;

    return 0;
}