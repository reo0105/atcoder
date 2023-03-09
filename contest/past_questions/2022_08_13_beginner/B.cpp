#include <bits/stdc++.h>
using namespace std;

int main()
{
    int r, c;
    int flag = 0;
    cin >> r >> c;

    if (max(abs(r-8), abs(c-8)) % 2 == 1) flag = 1;

    if (flag) cout << "black" << endl;
    else cout << "white" << endl;

    return 0; 
}
