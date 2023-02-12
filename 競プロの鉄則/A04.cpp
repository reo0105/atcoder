#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    bitset<10> x("0000000000");

    cin >> n;

    for (int i = 0; i < 10; i++) {
        if (n & 1) x.set(i, 1);
        n >>= 1;
    }

    cout << x << endl;

    return 0;
}