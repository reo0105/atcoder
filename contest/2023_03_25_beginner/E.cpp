#include <bits/stdc++.h>
#include <atcoder/modint>
using mint = atcoder::modint998244353;
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

int main()
{
    int n, m, k;
    vector<int> a(2005);

    cin >> n >> m >> k;

    // int mini = 5000;
    for (int i = 1; i <= n; i++) {
        cin >> a.at(i);
        // if (a.at(i) != 0) mini = min(mini, a.at(i));
    }

    mint ans = 1;
    mint p = 1, q = 1;

    // vector<int> b;
    int free = 0;
    map<int, int> mp;

    for (int i = 1; i <= n; i++) {
        if (a.at(i) == 0) {
            q *= m;
            free++;
        }   
        // else b.push_back(a.at(i));
        mp[a.at(i)]++;
    }

    // sort(b.begin(), b.end());
    // int szb = (int)b.size();

    vector<vector<mint>> dp(2005, vector<mint>(2005));
    vector<int> sum(2005, 0);
    for (int i =1; i <= n; i++) sum.at(i) += sum.at(i-1) + i;

    int de = 0;
    int id = 0;
    int pre = 1;
    // if (mini == 5000) pre = 1;

    for (int i = 1; i <= m; i++) {
        de += mp[i];

        if (de + free < k) continue;
        cout << "i " << i << endl;

        int use = k-de-1;
        mint low = modpow((i-pre+1), use);
        mint high = modpow((m-i+1), free-use);

        cout << low.val() << " " << high.val() << endl;

        if (use != 0) low *= (sum.at(i) - sum.at(pre-1)) / (i - pre + 1);
        if (free-use != 0) high *= (sum.at(m) - sum.at(i-1)) / (m - i + 1);

        cout << low.val() << " " << high.val() << endl;

        if (mp[i] != 0) pre = i;

        p += low * high * i; 
    }

    cout << p.val() << " " << q.val() << endl;

    ans = p / q;

    cout << ans.val() << endl;


    return 0;
}