#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<string> ans(n, string(n, '#'));
    
    for (int i = 0; i < n-1; i++)
    {
        int j = n-1-i;

        if (i > j) continue;

        char c;
        if (i % 2) c = '.';
        else c = '#';

        for (int li = 0; li < n; li++)
        {
            for (int lj = 0; lj < n; lj++)
            {
                if (i <= li && li <= j && i <= lj && lj <= j) ans[li][lj] = c;
            }
        }
    }
    
    for (int i = 0; i < n; i++) cout << ans[i] << endl;
    return 0;
}