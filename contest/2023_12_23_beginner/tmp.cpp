#include <bits/stdc++.h>
using namespace std;

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

ll modinv(ll y)
{
    return modpow(y, MOD-2);
}

int main()
{
    int h, w;
    cin >> h >> w;

    vector<string> s(h);
    for (int i = 0; i < h; i++) cin >> s[i];

    // Unionfind uf(h*w);

    vector<vector<int>> val(h, vector<int>(w, -1));
    int cnt = 0;

    vector<int> dir_i = {1, 0, -1, 0};
    vector<int> dir_j = {0, 1, 0, -1};

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '#' && val[i][j] == -1) {
                queue<int> que;
                val[i][j] = cnt;
                que.push(w*i+j);

                while (que.size()) {
                    int now = que.front();
                    que.pop();
                    int pi = now / w;
                    int pj = now % w;

                    for (int k = 0; k < 4; k++) {
                        int ni = pi + dir_i[k];
                        int nj = pj + dir_j[k];

                        if (ni == -1 || ni == h || nj == -1 || nj == w) continue;
                        if (val[ni][nj] != -1 || s[ni][nj] == '.') continue;

                        val[ni][nj] = cnt;
                        que.push(ni*w+nj);
                    }
                }
                cnt++;
            }
        }
    }

    vector<int> cnts(5, 0);

    int deno = 0;
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (s[i][j] == '.') {
                set<int> st;
                deno++;
                for (int k = 0; k < 4; k++) {
                    int ni = i + dir_i[k];
                    int nj = j + dir_j[k];

                    if (ni == -1 || ni == h || nj == -1 || nj == w) continue;
                    if (s[ni][nj] == '.') continue;

                    st.insert(val[ni][nj]);
                }

                int sz = (int)st.size();
                if (sz == 0) cnts[0]++;
                else if (sz == 1) cnts[1]++;
                else if (sz == 2) cnts[2]++;
                else if (sz == 3) cnts[3]++;
                else cnts[4]++;
            }
        }
    }

    ll ans = 0;
    for (int i = 0; i < 5; i++) {
        int nc = cnt;
        if (i == 0) nc++;
        else {
            nc -= i-1;
        }

        ans += (ll)nc * cnts[i];
        ans %= MOD;
    }


    cout << modinv(deno) * ans % MOD << endl;

    return 0;
}