#include <bits/stdc++.h>
using namespace std; 

/*
サイクル検出なのはすぐわかったけどmapでやったからかTLEしまくった

unordered_mapにしたらぎり通った
*/

// #pragma GCC target("avx2")
// #pragma GCC optimize("O3")
// #pragma GCC optimize("unroll-loops")
 
// unordered_map<string, int> s;//, t;
// vector<string> S(100005), T(100005);
// set<string> alter;
// vector<bool> ok(100005);
 
// bool dfs(int from)
// {
//     // cout << alter.at(T.at(from)) << " ";
//     ok.at(from) = true;
//     if (alter.count(T.at(from))) {
//         return true;
//     } else {
//         alter.insert(T.at(from));
//         // cout << T.at(from) << " " << s.at(T.at(from)) << endl;
//         if (s.count(T.at(from)) && dfs(s.at(T.at(from)))) return true;
//     }
 
//     if (alter.count(T.at(from))) alter.erase(T.at(from));
 
//     return false;
// }
 
// int main()
// {
//     int n, flag = 0;
//     ios::sync_with_stdio(false);
//     std::cin.tie(nullptr);
//     cin >> n;
 
//     for (int i = 0; i < n; i++) {
//         string x, y;
//         cin >> x >> y;
//         s[x] = i;
//         // t[y] = i;
//         S.at(i) = x;
//         T.at(i) = y;
//     }
 
    
//     for (int i = 0; i < n; i++) {
//         alter.insert(S.at(i));
//         if (!ok.at(i) && dfs(i)) {
//             flag = 1;
//             break;
//         }
//         if (alter.count(S.at(i))) alter.erase(S.at(i));
//     }
 
//     if (flag) {
//         cout << "No" << "\n";
//     } else {
//         cout << "Yes" << "\n";
//     }
 
//     return 0;
// }



map<string, int> seen;
map<string, string> G;

bool dfs(string from)
{
    seen[from] = 1;

    if (G.count(G.at(from))) {
        if (seen.count(G.at(from)) && seen.at(G.at(from)) == 1) return true;
        if (!seen.count(G.at(from)) && dfs(G.at(from))) return true;
    }

    seen[from] = -1;

    return false;
}

int main()
{
    int n;

    cin >> n;

    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        G[s1] = s2;
    }
    
    int flag = 0;
    for (auto next : G) {
        if (!seen.count(next.first) && dfs(next.first)) {
            flag = 1;
            break;
        }
    }

    if (flag) cout << "No" << endl;
    else cout << "Yes" << endl;
}