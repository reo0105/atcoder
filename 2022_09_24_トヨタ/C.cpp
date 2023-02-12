#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> path(200005);
vector<bool> check(200005, false);
bool stop = false;
deque<int> deq;

void dfs(int from, int to)
{
    if (!stop) deq.push_back(from);
    if (from == to) stop = true;

    check.at(from) = true;

    for (int next : path.at(from)) {
        if (check.at(next)) {
            continue;
        } else {
            dfs(next, to);
        }
    }

    if (!stop) deq.pop_back();
}


int main()
{
    int n, x, y, u, v;

    cin >> n >> x >> y;
    
    for (int i = 0; i < n; i++) {
        cin >> u >> v;
        path.at(u).push_back(v);
        path.at(v).push_back(u);
    }

    dfs(x, y);

    while(!deq.empty()) {
        cout << deq.front();
        deq.pop_front();
        if (!deq.empty()) cout << " ";
    }

    cout << endl;
}