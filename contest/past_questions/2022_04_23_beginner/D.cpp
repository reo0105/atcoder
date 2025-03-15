#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> enum_divisors(int n) 
{
    vector<int> res;
    for (int i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            res.push_back(i);
            // 重複しないならば i の相方である N/i も push
            if (n/i != i) res.push_back(n/i);
        }
    }
    // // 小さい順に並び替える
    // sort(res.begin(), res.end());
    return res;
}

int main()
{
    int n;
    ll ans = 0;
    vector<int> a(200005, 0);
    // map<int, ll> m;
    set<int> done;

    cin >> n;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.at(x)++;
    }

    // for (int i = 0; i < 10; i++) {
    //     if (m.count(i)) cout << m.at(i) << " ";
    //     else cout << 0 << " ";
    // }
    // cout << endl;

    for (int i = 1; i < 200005; i++) {
        vector<int> div;

        // if (done.count(a.at(i)) || a.at(i) == 0) continue;

        if (a.at(i) == 0) continue;
        // cout << i << " : " << a.at(i) << " / ";
        // done.insert(a.at(i));
        div = enum_divisors(i);

        for (int j = 0; j < (int)div.size(); j++) {
            int ak = i / div.at(j);
            // cout << div.at(j) << " = " << ak << endl;
            // if (m.count(div.at(j)) && m.count(ak)) {
                // if (a.at(i) == div.at(j) && div.at(j) == ak) {
                //     ll t = (ll)m.at(ak) * m.at(ak) * m.at(ak);
                //     ans += t;
                // } else if (a.at(i) == div.at(j)) {
                //     ll t = (ll)m.at(a.at(i)) * m.at(a.at(i)) * m.at(ak);
                //     ans += t;
                // } else if (div.at(j) == ak) {
                //     ll t = (ll)m.at(ak) * m.at(ak) * m.at(a.at(i));
                //     ans += t;
                // } else if (a.at(i) == ak) {
                //     ll t = (ll)m.at(ak) * m.at(ak) * m.at(div.at(j));
                //     ans += t;
                // } else {
                //     ans += m.at(ak) * m.at(div.at(j));
                // }
                ans += (ll)a.at(i) * a.at(ak) * a.at(div.at(j));
            // }
        }
    }


    // for (int a = 1; a <= 200005; a++) {
    //     for (int b = 1; b <= 200005 / a; b++) {
    //         int c = a * b;
    //         ans += (ll)m[a] * m[b] * m[c];
    //     }
    // }

    cout << ans << endl;

    return 0;
}