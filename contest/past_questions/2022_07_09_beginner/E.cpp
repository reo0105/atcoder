#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> m(200005);
    vector<int> p(200005), e(200005);
    map<int, int> mp;
    map<int, int> cnt;
    cin >> n;

    int id = 1;
    for (int i = 1; i <= n; i++) {
        cin >> m.at(i);
        for (int j = id; j < id + m.at(i); j++) {
            int prim, idx;
            cin >> prim >> idx;
            p.at(j) = prim;
            e.at(j) = idx;
            int now = mp[prim];
            if (idx > now) {
                mp[prim] = idx;
                cnt[prim] = 1;
            } else if (idx == now) {
                cnt[prim]++;
            }
        }
        id += m.at(i);
    }

    id = 1;
    int ans = 0;
    for (int i = 1; i <= n; i++)  {
        for (int j = id; j < id + m.at(i); j++) {
            int prim = p.at(j);
            int idx = e.at(j);
            if (idx == mp[prim] && cnt[prim] == 1) {
                ans++;
                // cout << i << endl;
                break;
            } 
        }
        id += m.at(i);
    }

    if (ans < n) ans++; // もともともLCM、消しても変わらない場合に＋１

    cout << ans << endl;

    return 0;
}