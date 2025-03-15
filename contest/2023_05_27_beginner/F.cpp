#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<ll, ll> pl;

/*
    2分探索。
    それぞれのターンにおける最適な行動が分かりそう。
*/

int main()
{
    int n;
    ll h;
    vector<p> td;//, d(300005);
    vector<pl> damage;//(300005);

    cin >> n >> h;
    for (int i = 0; i < n; i++) {
        int t, d;
        cin >> t >> d;
        td.push_back(make_pair(d, t));
        damage.push_back(pl(t * d, i));
    }

    sort(td.begin(), td.end());
    // sort(damage.rbegin(), damage.rend());


    vector<ll> best;



    ll l = 0, r = 1e18+5;

    while (r - l > 0) {
        ll mid = (l + r) / 2;


    }



    return 0;
}