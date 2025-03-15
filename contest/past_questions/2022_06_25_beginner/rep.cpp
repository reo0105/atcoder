#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

int main()
{
    int n, m;
    vector<vector<int>> G(300005);
    vector<int> undeside;

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        if (u == 0) undeside.push_back(v);
        else {
            G.at(u).push_back(v);
            G.at(v).push_back(u);
        }
    }

    vector<int> dist1(300005, -1);
    vector<int> distn(300005, -1);
    queue<int> que;

    dist1.at(1) = 0;
    que.push(1);
    
    while (que.size()) {
        int u = que.front();
        que.pop();

        for (int v : G.at(u)) {
            if (dist1.at(v) != -1) continue;

            dist1.at(v) = dist1.at(u) + 1;
            que.push(v);
        }
    } 

    if (dist1.at(n) == -1) {
        queue<int> que;

        dist1.at(n) = 0;
        que.push(n);
        
        while (que.size()) {
            int u = que.front();
            que.pop();

            for (int v : G.at(u)) {
                if (dist1.at(v) != -1) continue;

                dist1.at(v) = dist1.at(u) + 1;
                que.push(v);
            }
        }
    } else {
        distn = dist1;
    }

    //1とnが含まれる連結成分だけを考えてそこに行先未定があるか
    // set<int> undef1, undefn;
    int //最小の値がいる？

    for (int v : undeside) {
        if (dist1.at(v) != -1) undef1.insert(v);
        if (distn.at(v) != -1) undefn.insert(v); 
    }

    for (int i = 1; i <= n; i++) {
        if (undef1.count(i) && distn.at(i) != -1) {
            // ok
            int d = distn.at(i) + 1 + dist1.at()
            cout 
        } else if (undefn.count(i) && dist1.at(i) != -1) {
            //ok
        } else {
            // ng?
        }
    }


    return 0;
}