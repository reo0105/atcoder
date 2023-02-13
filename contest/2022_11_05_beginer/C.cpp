#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p.at(i);
    }
    
    prev_permutation(p.begin(), p.end());

    for (int i = 0; i < n; i++) {
        cout << p.at(i);
        if (i != n-1) cout << " ";
        else cout << endl;
    }

    return 0;
}