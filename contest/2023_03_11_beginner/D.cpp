#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(400005);
vector<bool> seen(400005, false);
bool cycle = false;

void dfs(int from, int prev)
{
    seen.at(from) = true;

    for (int n : G.at(from)) {
        if (n == prev) continue;

        if (seen.at(n)) {
            cycle = true;
            return;
        }
        dfs(n, from);
    }

    return;
}

int main()
{
    int n, m;
    // vector<int> a(200005), c(200005);
    // vector<char> b(200005), d(200005);
    
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, c;
        char b, d;
        // cin >> a.at(i) >> b.at(i) >> c.at(i) >> d.at(i);
        cin >> a >> b >> c >> d;
        
        if (b == 'R') {
            a = a*2-1;
        } else if (b == 'B') {
            a = a*2;
        }
        if (d == 'R') {
            c = c*2-1;
        } else if (d == 'B') {
            c = c*2;
        }

        G.at(a).push_back(c);
        G.at(c).push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        G.at(2*i).push_back(2*i-1);
        G.at(2*i-1).push_back(2*i);
    }

    int x = 0, y = 0;

    for (int i = 1; i <= 2*n; i++) {
        if (!seen.at(i)) {
            cycle = false;
            dfs(i, -1);
            // cout << i << " " << cycle << endl;
            if (cycle) x++;
            else y++;
        }
    }

    cout << x << " " << y << endl;

    return 0;

}