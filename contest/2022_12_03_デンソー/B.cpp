#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long n, t;
    vector<long long> s(12), ans(12);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s.at(i);
    }

    t = s.at(0);
    ans.at(0) = t;

    for (int i = 1; i < n; i++) {
        ans.at(i) = s.at(i) - t;
        t += ans.at(i);
    }

    for (int i = 0; i < n; i++) {
        cout << ans.at(i);
        if (i == n-1) cout << endl;
        else cout << " ";
    }


    return 0;
}