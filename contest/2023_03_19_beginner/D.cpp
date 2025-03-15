#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    set<int> peo, called, gone;

    cin >> n >> q;
    for (int i = 1; i <= n; i++) peo.insert(i);

    for (int i = 0; i < q; i++) {
        int e, x;
        cin >> e;
        
        if (e == 1) {
            int mini = *begin(peo);
            peo.erase(mini);
            called.insert(mini);
        } else if (e == 2) {
            cin >> x;
            called.erase(x);
            gone.insert(x);
        } else {
            int mini = *begin(called);
            cout << mini << endl;
        }
    }

    return 0;
}