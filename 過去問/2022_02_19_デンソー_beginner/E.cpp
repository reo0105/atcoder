#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p; 

vector<int> x(100005);
vector<vector<int>> G(100005);
vector<vector<int>> num(100005);

void merge(vector<int> &target, vector<int> &from)
{
    target.insert(target.end(), from.begin(), from.end());
    sort(target.rbegin(), target.rend());
    target.resize(20);

    return;
}

void dfs(int from, int par)
{
    num.at(from).push_back(x.at(from));

    for (int next : G.at(from)) {
        if (next == par) continue;
        dfs(next, from);
        merge(num.at(from), num.at(next));
    }

    return;
}


int main()
{
    int n, q;

    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> x.at(i);

    for (int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    dfs(1, -1);

    // for (int i = 1; i <= n; i++) {
    //     for (int next : num.at(i)) {
    //         cout << next << " ";
    //     }
    //     cout << endl;
    // }

    for (int i = 0; i < q; i++) {
        int v, k;
        cin >> v >> k;
        cout << num.at(v).at(k-1) << endl;
    }

    return 0;
}