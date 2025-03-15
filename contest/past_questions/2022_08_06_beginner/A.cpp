#include <bits/stdc++.h>
using namespace std;

int main()
{
    int a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    map<int, int> mp;

    mp[a]++;
    mp[b]++;
    mp[c]++;
    mp[d]++;
    mp[e]++;

    int flag = 1;
    for (auto p : mp) {
        if (p.second != 3 && p.second != 2) flag = 0;
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    return 0;
}