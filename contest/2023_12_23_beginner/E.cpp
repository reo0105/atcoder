#include <bits/stdc++.h>
using namespace std;

#define MOD 998244353
typedef pair<int, int> pii;
typedef long long ll;

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


ll modinv(ll x)
{
    return modpow(x, MOD-2);
}

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> s(h);

    for (int i = 0; i < h; i++) cin >> s[i];

    int cnt = 0;
    vector<vector<int>> dist(h, vector<int>(w, -1));

    vector<int> dir_i = {0, -1, 0, 1};
    vector<int> dir_j = {1, 0, -1, 0};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (dist[i][j] == -1 && s[i][j] == '#') {
                cnt++;

                queue<pii> que;
                que.push(make_pair(i, j));
                dist[i][j] = cnt;

                while (que.size()) {
                    pii now = que.front();
                    que.pop();

                    int pi = now.first;
                    int pj = now.second;

                    for (int k = 0; k < 4; k++) {
                        int ni = pi + dir_i[k];
                        int nj = pj + dir_j[k];

                        if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;
                        if (dist[ni][nj] == -1 && s[ni][nj] == '#') {
                            dist[ni][nj] = cnt;
                            que.push(make_pair(ni, nj));
                        }
                    }
                }
            }
        }
    }

    vector<ll> minus(5, 0);

    ll numerator = 0;
    ll denominator = 0;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                denominator++;
                set<int> kinds;

                for (int k = 0; k < 4; k++) {
                    int ni = i + dir_i[k];
                    int nj = j + dir_j[k];

                    if (ni < 0 || ni >= h || nj < 0 || nj >= w) continue;

                    if (s[ni][nj] == '#') kinds.insert(dist[ni][nj]);
                }

                minus[(int)kinds.size()]++;
            }
        }
    }

    for (int i = 0; i < 4; i++) {
        numerator += (cnt - i) * minus[i+1] % MOD;
    }
    numerator += (cnt + 1) * minus[0];
    numerator %= MOD;


    cout << (modinv(denominator) * (ll)numerator) % MOD << endl;

    return 0;
}