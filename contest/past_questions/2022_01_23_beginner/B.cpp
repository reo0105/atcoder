#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n;
    vector<int> a(400005, 0);
 
    cin >> n;
    for (int i = 0; i < 4*n - 1; i++) {
        int x;
        cin >> x;
        a.at(x) += 1;
    }
 
    for (int i = 1; i <= n; i++) {
        if (a.at(i) != 4) {
            cout << i << endl;
            break;
        }
    }
 
    return 0;
}