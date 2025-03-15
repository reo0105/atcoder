#include <bits/stdc++.h>
using namespace std;

map<int, vector<int>> G;
set<int> seen;

void dfs(int from)
{
    seen.insert(from);
    
    if (G.count(from)) {
        for (int next : G.at(from)) {
            if (seen.count(next)) continue;
            // if (next > ans) ans = next;
            dfs(next);
        }
    }

}

int main()
{
    int n, a, b, ans;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a); 
    }

    dfs(1);


    cout << *rbegin(seen) << endl;



    return 0;
}