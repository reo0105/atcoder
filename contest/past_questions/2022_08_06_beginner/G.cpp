#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
typedef long long ll;


int main()
{
    int n;
    cin >> n;
    map<int, int> mp;
    mp[1] = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        mp[a] += b;
    }

    n = mp.size();

    int sv = n, tv = sv+1;
    mf_graph<ll> g(tv+1);
    int one = mp[1] / 2;
    mp[1] %= 2;

    int i = 0;
    vector<int> odd, even;
    for (auto [a, b] : mp) {
        if (a%2) {
            odd.push_back(i);
            g.add_edge(sv, i, b);
        } else {
            even.push_back(i, tv, b);
        }
        i++;
    }

    for (int o : odd) {
        for (int e : even) {
            
        }
    }

}