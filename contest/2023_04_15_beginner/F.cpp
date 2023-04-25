#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, int> pl;

int main()
{
    int n;
    map<int, ll> mpr, mpc;
    map<p, int> point;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int r, c;
        ll x;
        cin >> r >> c >> x;
        mpr[r] += x;
        mpc[c] += x;
        point[make_pair(r, c)] = x;
    }

    vector<pl> sumr, sumc; 

    ll t = 0;
    for (p x : mpr) sumr.push_back(make_pair(x.second, x.first));
    for (p x : mpc) sumc.push_back(make_pair(x.second, x.first));
    
    sort(sumr.rbegin(), sumr.rend());
    sort(sumc.rbegin(), sumc.rend());

    ll ans = 0;
    int szr = (int)sumr.size();
    int szc = (int)sumc.size();
    for (int i = 0; i < szr; i++) {
        ll now = sumr.at(i).first;
        int nowr = sumr.at(i).second;

        for (int j = 0; j < szc; j++) {
            now += sumc.at(j).first;
            int nowc = sumc.at(j).second;
            int sel = point[make_pair(nowr, nowc)];
            if (sel != 0) {
                now -= sel; 
                ans = max(now, ans);
                now += sel;
                now -= sumc.at(j).first;
            } else {
                ans = max(now, ans);
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;    
}