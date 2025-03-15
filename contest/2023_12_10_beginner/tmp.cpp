#include <bits/stdc++.h>
using namespace std;
#include <atcoder/all>
using namespace atcoder;

typedef long long ll;
#define MOD 998244353


ll modpow(ll a, ll y)
{
    ll ret = 1;

    while (y > 0) {
        if (y & 1) ret = ret * a % MOD;
        a = a * a % MOD;
        y >>= 1;
    }

    return ret;
}

int main()
{
    int h, w;
    cin >> h >> w;

    vector<vector<int>> a(h, vector<int>(w));
    vector<vector<int>> b(h, vector<int>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> b[i][j];
        }
    }

    vector<int> h_idx;
    vector<int> w_idx;

    for (int i = 0; i < h; i++) h_idx.push_back(i);
    for (int j = 0; j < w; j++) w_idx.push_back(j);

    const int inf = 1e9;
    int ans = inf;

    do {
        do {

            int ok = 1;

            for (int i = 0; i < h; i++) {
                for (int j = 0; j < w; j++) {
                    if (a[h_idx[i]][w_idx[j]] != b[i][j]) ok = 0;
                }
            }

            if (ok) {
                int t = 0;
                for (int i = 0; i < h; i++) {
                    for (int j = i+1; j < h; j++) {
                        if (h_idx[i] > h_idx[j]) t++;
                    }
                }

                for (int i = 0; i < w; i++) {
                    for (int j = i+1; j < w; j++) {
                        if (w_idx[i] > w_idx[j]) t++;
                    }
                }

                ans = min(ans, t);
            }


        } while (next_permutation(h_idx.begin(), h_idx.end()));
    } while (next_permutation(w_idx.begin(), w_idx.end()));
    
    if (ans == inf) ans = -1;

    cout << ans << endl;

    return 0;  
}