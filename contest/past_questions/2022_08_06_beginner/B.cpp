#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> p(53);

    cin >> n;
    for (int i = 2; i <= n; i++) cin >> p.at(i);
    
    int ans = 0;
    int par = n;

    while (par != 1) {
        par = p.at(par);
        ans++;
    }

    cout << ans << endl;


    return 0;
}