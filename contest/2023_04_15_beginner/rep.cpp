#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, ll> pll;
#define MOD 998244353

int main()
{
    int n;
    cin >> n;

    map<int, ll> mpr, mpc;
    map<p, int> point;

    for (int i = 0; i < n; i++) {
        int r, c, x;
        cin >> r >> c >> x;
        mpr[r] += x;
        mpc[c] += x;
        point[make_pair(r, c)] = x;
    }

    vector<pll> sumr, sumc;
    pll tmp;
    for (auto x : mpr) {
        tmp.first = x.second;
        tmp.second = x.first;
        sumr.push_back(tmp);
    }

    for (auto x : mpc) {
        tmp.first = x.second;
        tmp.second = x.first;
        sumc.push_back(tmp);
    }

    sort(sumr.rbegin(), sumr.rend());
    sort(sumc.rbegin(), sumc.rend());

    int szr = (int)sumr.size();
    int szc = (int)sumc.size();

    ll ans = 0;
    for (int i = 0; i < szr; i++) {
        ll now = sumr.at(i).first;
        int nowr = sumr.at(i).second;
        
        for (int j = 0; j < szc; j++) {
            now += sumc.at(j).first;
            int nowc = sumc.at(j).second;

            if (point.count(make_pair(nowr, nowc))) {
                now -= point[make_pair(nowr, nowc)];
                ans = max(ans, now);
                now += point[make_pair(nowr, nowc)];
                now -= sumc.at(j).first;
            } else {
                ans = max(ans, now);
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}