#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<pii> lr(m);
    vector<int> paint(m, 0);

    for (int i = 0; i < m; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        lr[i].first = l;
        lr[i].second = r;

        paint[i] = l-r+1;
    }

    priority_queue<pii, vector<pii>, greater<pii>> que; 

    for (int i = 0; i < m; i++) {
        que.push(make_pair(lr[i].second-lr[i].first+1, i));
    }

    int cnt = 0;
    int ans = 0;

    vector<int> write(n, 0);
    vector<bool> done(n, false);

    while (que.size()) {
        pii top = que.top();
        que.pop();

        int l = lr[top.second].first;
        int r = lr[top.second].second;

        if (write[r] - write[l] == l-r) continue;
        ans++;

        if (!done[l]) {
            write[l]++;
            done[l] = true;
        }
        for (int i = l+1; i <= r; i++) {
            if (!done[i]) {
                write[i] = write[i-1] + 1;
                done[i] = true;
            } else {
                write[i] = write[i-1];
            }
        }
        for (int i = r+1; i < n; i++) {
            write[i] = write[i-1];
        }

        for (int i = 0; i < m; i++) {
            int now_cnt = paint[i];
            if (now_cnt == 0) continue;
            if (i == top.second) {
                paint[i] = 0;
                continue;
            }

            int li = lr[i].first;
            int ri = lr[i].second;

            if (ri < l || r < li) continue;

            if (li <= r && r <= ri) {
                paint[i] = max(0, paint[i]-(r-li+1));
                if (paint[i] != 0) que.push(make_pair(ri-(r+1)+1, i));
            }
            if (li <= l && l <= ri) {
                paint[i] = max(0, paint[i]-(ri-l+1));
                if (paint[i] != 0) que.push(make_pair(r-(ri+1)+1, i));
            }
        }
    }

    cout << ans << endl;

    return 0;
}

