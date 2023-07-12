#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;
typedef long long ll;

int main()
{
    
    int n1, n2, m;
    vector<vector<int>> G(300005);

    cin >> n1 >> n2 >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        G.at(a).push_back(b);
        G.at(b).push_back(a);
    }

    vector<int> dist1(300005, -1);
    vector<int> dist2(300005, -1);

    queue<int> que;
    int maxi1 = 0, maxi2 = 0;

    que.push(1);
    dist1.at(1) = 0;
    while (que.size()) {
        int top = que.front();
        que.pop();

        for (int u : G.at(top)) {
            if (dist1.at(u) != -1) continue;
            dist1.at(u) = dist1.at(top) + 1;
            maxi1 = dist1.at(u);
            que.push(u);
        }
    }

    que.push(n1+n2);
    dist2.at(n1+n2) = 0;
    while (que.size()) {
        int top = que.front();
        que.pop();

        for (int u : G.at(top)) {
            if (dist2.at(u) != -1) continue;
            dist2.at(u) = dist2.at(top) + 1;
            maxi2 = dist2.at(u);
            que.push(u);
        }
    }

    cout << maxi1 + maxi2 + 1 << endl;

    return 0;
}