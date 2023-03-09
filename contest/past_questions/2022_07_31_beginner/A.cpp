#include <bits/stdc++.h>
using namespace std;

int main()
{
    int y;
    cin >> y;

    if ((y-2)%4 == 1) y += 3; 
    else if ((y-2)%4 == 2) y += 2; 
    else if ((y-2)%4 == 3) y += 1; 

    cout << y << endl;

    return 0;
}