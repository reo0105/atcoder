#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> a;

    while (1) {
        int t;
        cin >> t;
        a.push_back(t);

        if (t == 0) break;
    }

    for (int i = (int)a.size()-1; i>= 0; i--) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}