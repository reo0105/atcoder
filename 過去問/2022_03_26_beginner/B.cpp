#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    set<int> s;

    cin >> n;
    
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s.insert(a);
    }

    int ans = 0;

    for (int i = 0; i <= 2000; i++) {
        if (!s.count(i)) {
            ans = i;
            break;
        }
    }

    cout << ans << endl;

    return 0;
}