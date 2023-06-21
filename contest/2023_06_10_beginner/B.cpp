#include <bits/stdc++.h>
using namespace std;

int main()
{
    char p, q;
    cin >> p >> q;

    if (p > q) swap(p, q);

    vector<int> a = {0, 3, 4, 8, 9, 14, 23};

    cout << a.at(q-'A') - a.at(p-'A') << endl;

    return 0;
}