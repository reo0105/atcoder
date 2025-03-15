#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<set<int>> s(200005);
    vector<vector<int>> G(200005);
    vector<set<int>> where(200005); //ある数iがどの頂点（集合）に含まれるか

    for (int i = 1; i <= n; i++) {
        int a;
        cin >> a;
        for (int j = 0; j < a; j++) {
            int x;
            cin >> x;
            s.at(i).insert(x);
            where.at(x).insert(i);
        }
    }

    vector<int> start;
    set<int>end;

    int cnt;
    for (int i = 1; i <= n; i++) {
        cnt = 0;
        if (s.at(i).count(1)) { start.push_back(i); cnt++; }
        if (s.at(i).count(m)) { end.insert(i); cnt++; }
        if (cnt == 2) {
            cout << 0 << endl;
            return 0;
        }
    }

    queue<p> que;
    vector<int> dist(200005, -1);

    for (int i = 0; i < (int)start.size(); i++) {
        que.push(make_pair(1, start.at(i)));
        dist.at(start.at(i)) = 0;
        // cout << start.at(i) << " "; 
    }
    // cout << endl;

    set<int> done;
    done.insert(1);

    while (que.size()) {
        int num = que.front().first;
        int u = que.front().second;
        que.pop();

        for (int x : s.at(u)) {
            // cout << x << " ";
            if (done.count(x)) continue;
            for (int v : where.at(x)) {
                // cout << v << " ";
                if (dist.at(v) != -1) continue;

                dist.at(v) = dist.at(u) + 1;
                que.push(make_pair(x, v));
                done.insert(x);
                if (end.count(v)) {
                    cout << dist.at(v) << endl;
                    return 0;
                }
            }
            // cout << endl;
        }
    }

    cout << -1 << endl;

    return 0;
}