#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> p(n, 0), t(n, 0);
    for (int i = 0; i < n-1; i++) cin >> p[i] >> t[i];

    int Q;
    cin >> Q;
    vector<int> q(Q);
    for (int i = 0; i < Q; i++) cin >> q[i];

    vector<int> type_q(q);
    for (int i = 0; i < Q; i++) {
        type_q[i] = q[i] % 840;
    }

    vector<ll> type(840, 0);
    for (int i = 0; i < 840; i++) {
        type[i] = i + x;
        int rem = type[i] % p[0];
        type[i] += (p[0] - rem) % p[0];
        for (int j = 0; j < n-1; j++) {
            type[i] += t[j];
            if (j == n-2) break;
            int rem = type[i] % p[j+1];
            type[i] += (p[j+1] - rem) % p[j+1];
        }
        type[i] -= i;
    }

    for (int i = 0; i < Q; i++) {
        cout << q[i] + type[type_q[i]] + y << '\n';
    }

    return 0;

}