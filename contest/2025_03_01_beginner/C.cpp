#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(1e6+5);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a[x].emplace_back(i);
    }

    int ans = 1e9;
    for (int i = 0; i < 1e6+1; i++)
    {
        for (int j = 0; j < (int)a[i].size()-1; j++)
        {
            ans = min(ans, a[i][j+1]-a[i][j]+1);
        }
    }

    cout << (ans == 1e9 ? -1 : ans) << endl;
    
    return 0;
}