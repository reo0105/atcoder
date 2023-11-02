#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a = {1, 2, 3};
    vector<int> b;

    b = a;
    b[0] = 0;
    for (int i = 0; i < 3; i++) cout << a[i];
    for (int i = 0; i < 3; i++) cout << b[i];

    return 0;
}