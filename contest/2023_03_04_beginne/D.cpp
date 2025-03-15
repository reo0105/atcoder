#include <bits/stdc++.h>
using namespace std;

// vector<int> dist(200005, 0);
// vector<vector<int>> G(200005);
// int loop = 0;
// int num = 0;
// int num1 = 0;

// int dfs(int from, int cnt)
// {
//     dist.at(from) = cnt;
//     num1++;

//     for (int v : G.at(from)) {
//         //  cout << "from : v" << from << " " << v << endl;
//         // if (dist.at(v) == cnt) {
//         //     // cout << 'b' << endl;
//         //     return 1;
//         // }
//         num++;
//         if (dist.at(v) != 0 && dist.at(v) == cnt) {
//             // cout << 'a' << endl;
//             continue;
//         }

//         if (dfs(v, cnt) == 1) loop = 1;
//     }

//     if (loop) return 1;

//     return 0;
// }

// int main()
// {
//     int n, m;
//     cin >> n >> m;
//     int flag = 1;
//     // vector<set<int>> edge(200005);


//     for (int i = 0; i < m; i++) {
//         int u, v;
//         cin >> u >> v;
//         G.at(u).push_back(v);
//         G.at(v).push_back(u);
//         // if (edge.at(u).count(v)) flag = 0;
//         // else edge.at(u).insert(v);

//         // if (edge.at(v).count(u)) flag = 0;
//         // else edge.at(v).insert(u);
//     }

//     int cnt = 1, loop = 0;

//     if (n != m) flag = 0;
//     else {
//         for (int i = 1; i <= n; i++) {
//             if (dist.at(i) == 0) {
//                 // cout << i << endl;
//                 loop = 0;
//                 if ((int)G.at(i).size() == 0) flag = 0;
//                 else if (dfs(i, cnt) == 0 && num / 2 != num1) flag = 0;
//                 // cout << flag << endl;
//                 cnt++;
//                 // cout << num << " " << num1 << endl;
//                 num = 0;
//                 num1 = 0;
//             }
//         }
//     }

//     if (flag) cout << "Yes" << endl;
//     else cout << "No" << endl;

//     return 0;
// }

typedef pair<int, int> p;
struct UnionFind
{
    // データiが属する木の親番号
    vector<p> par;

    UnionFind(int n) {
        par.assign(n, make_pair(-1, 0));
    }

    int root(int x) {
        return par.at(x).first < 0 ? x : (par.at(x).first = root(par.at(x).first));
    }

    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) { par.at(x).second++; return; }
        if (par.at(x).first > par.at(y).first) swap(x, y);
        par.at(x).first += par.at(y).first;
        par.at(x).second += par.at(y).second+1;
        par.at(y).first = x;
    }

    bool equal(int x, int y) {
        return root(x) == root(y);
    }
};

int main()
{
    int n, m;
    int flag = 1;
    UnionFind uf(200005);
    
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        uf.unite(u, v);
    }

    for (int i = 1; i <= n; i++) {
        if (uf.par.at(i).first < 0) {
            int s = -uf.par.at(i).first;
            int e =  uf.par.at(i).second;
            // cout << i << " " << s << " " << e << endl;
            if (s != e) flag = 0;
        }
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}