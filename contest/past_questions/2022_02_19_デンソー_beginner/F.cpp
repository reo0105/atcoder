#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

vector<int> d(200005);
vector<int> num(200005);
vector<vector<int >> G(200005);
vector<bool> seen(200005, false);
vector<bool> finished(200005, false);

int dfs(int from, int pre, int id)
{
    seen.at(from) = true;
    num.at(from) = id;

    for (int v : G.at(from)) {
        if (v == pre) continue;
        if (seen.at(v) && !finished.at(v)) return -1;

        d.at(from)--;
        d.at(v)--;
        dfs(v, from, id);
    }

    finished.at(from) = true;

    return 0;
}



int main()
{
    int n, m;

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> d.at(i);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    ll sum = 0;
    for (int i = 1; i <= n; i++) sum += d.at(i);

    if (sum != (n-1)*2) cout << -1 << endl;
    else {
        int id = 1;
        for (int i = 1; i <= n; i++) {
            if (!seen.at(i)) {
                if (dfs(i, -1, id) == -1) {
                    cout << -1 << endl;
                    return 0;
                }
                id++;
            }
        }

        // cout << id << endl;

        vector<int> rem(id+1, 0);
        vector<vector<int>> con(id+1);
        for (int i = 1; i <= n; i++) {
            rem.at(num.at(i)) += d.at(i);
            if (d.at(i) != 0) {
                for (int j = 0; j < d.at(i); j++) con.at(num.at(i)).push_back(i);
            }
        }

        for (int i = 1; i <= n; i++) {
            if (d.at(i) < 0) {
                cout << -1 << endl;
                return 0;
            }
        }


        for (int i = 1; i < id; i++) {
            if (rem.at(i) <= 0) {
                cout << -1 << endl;
                return 0;
            }
        }

        // for (int i = 1; i <= id; i++) {
        //     for (int x : con.at(i)) {
        //         cout << x << " ";
        //     }
        //     cout << endl;
        // }

        set<p> s;
        for (int i = 1; i < id; i++) s.insert(make_pair(rem.at(i), i));

        while (s.size()) {
            p mini = *begin(s);
            p maxi = *rbegin(s);
            
            s.erase(mini);
            s.erase(maxi);

            int id0 = mini.second;
            int id1 = maxi.second;

            // cout << id0 << " " << id1 << endl;

            mini.first--;
            maxi.first--;

            // cout << con.at(id0).size() << " " << con.at(id1).size() << endl;

            cout << con.at(id0).back() << " " << con.at(id1).back() << endl;
            con.at(id0).pop_back();
            con.at(id1).pop_back();
            if (mini.first != 0) s.insert(make_pair(mini.first, id0));
            if (maxi.first != 0) s.insert(make_pair(maxi.first, id1));
        }
    }

    return 0;    
}