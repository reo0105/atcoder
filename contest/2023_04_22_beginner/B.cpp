#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> c(200005), r(200005);

    int flag = 0;
    for (int i = 0; i < n; i++) {
        cin >> c.at(i); 
        if (c.at(i) == t) flag = 1;
    }

    for (int i = 0; i < n; i++) cin >> r.at(i);

    if (!flag) t = c.at(0);
    int maxi = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (c.at(i) == t && maxi < r.at(i)) {
            maxi = r.at(i);
            ans = i+1;
        }
    } 

    cout << ans << endl;

    return 0;
}