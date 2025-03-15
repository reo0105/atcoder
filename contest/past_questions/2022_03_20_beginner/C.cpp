#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    set<int> s;

    cin >> n;

    for (int i = 0; i <= 2*n+1; i++) {
        s.insert(i);
    }

    while(!s.empty()) {
        int x;
        x = *rbegin(s);
        cout << x << endl;
        flush(cout);
        s.erase(x);
        cin >> x;
        s.erase(x);
    }

    return 0;
}
