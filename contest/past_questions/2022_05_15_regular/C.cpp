#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;

    cout << x << " ";
    vector<bool> done(200005, false);
    done.at(x) = true;

    if (n % 2 == 0 && x <= n/2+1) x = n/2 + 1;
    else if (n % 2 == 0) x = n/2;
    else if (n % 2 == 1 && x <= (n+1)/2) x = (n+1)/2+1;
    else x = (n+1) / 2;

    int cnt = 1;
    int minus = 1, plus = 1;
    if (!done.at(x)) { cout << x << " "; done.at(x) = true; cnt++; } 
    while (cnt != n) {
        while (x-minus >= 1 && done.at(x-minus)) minus++;
        if (x-minus >= 1 && !done.at(x-minus)) { cout << x-minus << " "; done.at(x-minus) = true; cnt++;}
        while (x+plus <= n && done.at(x+plus)) plus++;
        if (x+plus <= n && !done.at(x+plus)) { cout << x+plus << " "; done.at(x+plus) = true; cnt++; }
    }
    cout << endl;

    return 0;
}