#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, a;
    cin >> n >> a;

    int end = 0;
    int wait = 0;

    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;

        if (end > t) wait++;
        else if (wait != 0) wait--;

        if (wait == 0) end = t + a;
        else { end += a; wait--; }
        cout << end  << endl;
    }

}