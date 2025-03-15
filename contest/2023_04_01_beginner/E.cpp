#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G(200005); 
vector<bool> seen(200005, false);
vector<bool> finished(200005, false);

int pos = -1;
stack<int> hist;

void dfs(int from, int pre)
{
    seen.at(from) = true;
    hist.push(from);

    for (auto nv : G.at(from)) {

        // cout << "from " << from << " nv " << nv << endl; 
        if (finished.at(nv)) continue;
        // cout << "from " << from << " nv " << nv << endl; 

        if (seen.at(nv) && !finished.at(nv)) {
            pos = nv;
            return;
        }

        dfs(nv, from);

        if (pos != -1) return;
    }

    finished.at(from) = true;
    hist.pop();
}

int main()
{
    int n;
    
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        G.at(i).push_back(x);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (!seen.at(i)) {
            dfs(i, -1);

            set<int> cycle;
            while (hist.size()) {
                int t = hist.top();
                finished.at(t) = true;
                // cout << t << " ";
                cycle.insert(t);
                hist.pop();
                if (t == pos) break;
            }
            // cout << endl;

            ans += (int)cycle.size();
            pos = -1;
            while (hist.size()) {
                int t = hist.top();
                finished.at(t) = true;
                hist.pop();
            }
        }
    }

    cout << ans << endl;

    return 0;
}