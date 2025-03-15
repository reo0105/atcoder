#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define MOD 998244353

typedef pair<int, int> pii;

int main()
{
    int n, x, y;
    cin >> n >> x >> y;

    vector<int> p(n-1), t(n-1);
    for (int i = 0; i < n-1; i++) cin >> p[i] >> t[i];

    int q;
    cin >> q;

    vector<ll> type(840, 0);

    for (int i = 0; i < 840; i++) {
        type[i] = i+x;
        int rem = type[i] % p[0];
        type[i] += (p[0] - rem) % p[0];
        for (int j = 0; j < n-1; j++) {
            type[i] += t[j];
            if (j == n-2) break;
            rem = type[i] % p[j+1];
            type[i] += (p[j+1] - rem) % p[j+1];
        }
        type[i] -= i;
    }

    for (int i = 0; i < q; i++) {
        int qi;
        cin >> qi;
        ll ans = qi + type[qi%840] + y;
        cout << ans << endl;
    }
    
    return 0;
}