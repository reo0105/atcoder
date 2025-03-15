#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    int i, j;
    for (i = 1; i <= n-1; i++) {
        for (j = 1; j+i <= n; j++) {
            if (s.at(j-1) == s.at(j+i-1)) break;
        }
        cout << j-1 << endl;
    }
    

    return 0;
}