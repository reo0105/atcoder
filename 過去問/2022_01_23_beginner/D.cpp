#include <bits/stdc++.h>
using namespace std;
 
vector<vector<int>> a(20, vector<int>(20));
int n, n2, ans = 0;
 
int dfs(vector<bool> seen, int tmp)
{
    int i;
    for (i = 0; i < n2; i++) {
        if (!seen.at(i)) {
            break;
        }
    }
 
    if (i == n2) return ans = max(ans, tmp);
 
    seen.at(i) = true;
 
    for (int j = 0; j < n2; j++) {
        if (!seen.at(j)) {
            int tmp2 = tmp ^ a.at(i).at(j);
            seen.at(j) = true;
            dfs(seen, tmp2);
            seen.at(j) = false;
        }
    }
 
    return ans;
}
 
 
int main()
{
    cin >> n;
    n2 = n*2;
 
    for (int i = 0; i < n2-1; i++) {
        for (int j = i+1; j < n2; j++) {
            cin >> a.at(i).at(j);
        }
    }
 
    vector<bool> seen(20, false);
    dfs(seen, 0);
    cout << ans << endl;
 
    return 0;
}