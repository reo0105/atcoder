#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef pair<ll, int> pli;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<ll> l(m), d(m), k(m), c(m) , A(m), B(m);
    vector<vector<pii>> G(n+5);

    for (int i = 0; i < m; i++) {
        cin >> l[i] >> d[i] >> k[i] >> c[i] >> A[i] >> B[i];
        G[B[i]-1].push_back(make_pair(A[i]-1, i));
    }

    priority_queue<pli> que;
    que.push(make_pair(2e18, n-1));
    vector<ll> ans(n, -1);
    ans[n-1] = 2e18;

    while (que.size()) {
        pli maxi = que.top();
        que.pop();

        int from = maxi.second;
        ll nc = maxi.first;

        for (pii p : G[from]) {
            int to = p.first;
            int idx = p.second;

            if (ans[to] >= ans[from]) continue;

            ll lim = nc - c[idx];
            ll start = l[idx];
            ll end = l[idx] + (k[idx] - 1) * d[idx];
            ll new_c;
            
            if (lim >= end) new_c = end;
            else if (start <= lim && lim < end) {
                ll loop = (lim - start) / d[idx];
                new_c = start + loop * d[idx];
            } else {
                new_c = -1;
            }

            if (ans[to] < new_c) {
                ans[to] = new_c;
                que.push(make_pair(new_c, to));
            }
        }
    }

    for (int i = 0; i < n-1; i++) {
        if (ans[i] == -1) cout << "Unreachable" << endl;
        else cout << ans[i] << endl;
    }


    
}