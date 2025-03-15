#include <bits/stdc++.h>
using namespace std;
 
int main()
{
    int n, erase;
    vector<int> a(200005);
 
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a.at(i);
 
    int i;
    for (i = 0; i < n-1; i++) {
        if (a.at(i) > a.at(i+1)) break;
    }
 
    erase = i;
    for (int i = 0; i < n; i++) {
        if (a.at(i) != a.at(erase)) {
            cout << a.at(i) << " ";
        }
    }
    cout << endl;
 
    return 0;
}