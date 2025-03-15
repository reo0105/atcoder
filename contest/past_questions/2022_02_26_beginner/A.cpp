#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int n;
    vector<int> a(10);
    
    for (int i = 0; i < 10; i++) cin >> a.at(i);

    int now = 0;
    for (int i = 0; i < 3; i++) {
        now = a.at(now);
        // cout << now << endl;
    }

    cout << now << endl;

    return 0;
}