#include <bits/stdc++.h>
using namespace std;

int main()
{
    int l, r;
    string s = "atcoder";

    cin >> l >> r;
    for (int i = l-1; i < r; i++) cout << s.at(i);

    return 0; 
}
