#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    vector<vector<int>> G(n+5);
    for (int i = 2; i <= n; i++) {
        int temp;
        cin >> temp;

        G[temp].push_back(i);
    }

    queue<pii> que;

    que.push(make_pair(1, 1));

    int cnt = 1;
    vector<ll> t(n+3, 0);

    t[0] = a[1];
    while(que.size()) {
        pii now = que.front();
        que.pop();
        cnt = now.second;

        for (int x : G[now.first]) {
            que.push(make_pair(x, now.second+1));
            t[cnt] += a[x];
        }
    }


    for (int i = cnt-1; i >= 0; i--) {
        if (t[i] > 0) {
            cout << "+" << endl;
            return 0;
        } else if (t[i] < 0) {
            cout << "-" << endl;
            return 0;
        }
    }

    cout << 0 << endl;

    return 0;
}