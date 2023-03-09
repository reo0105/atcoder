#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l1, r1, l2, r2;
    cin >> l1 >> r1 >> l2 >> r2;

    int sum = 0;

    if (l2 <= l1 && l1 <= r2 && r2 <= r1) sum = r2 - l1;
    else if (l1 <= l2 && l2 <= r1 && r1 <= r2) sum = r1 - l2;
    else if (l1 <= l2 && r2 <= r1) sum = r2 - l2;
    else if (l2 <= l1 && r1 <= r2) sum = r1 - l1;
    else if (l1 <= l2 && l2 <= r1 && r1 <= r2) sum = r1 - l2;
    else if (l2 <= l1 && l1 <= r2 && r2 <= r1) sum = r2 - l1;

    cout << sum << endl;

    return 0;
}