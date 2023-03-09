#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
全体の個数から回文の個数をひくという考え方まではできたけど、引き方の実装が
できなかった。
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
全体の個数から回文の個数をひくという考え方まではできたけど、引き方の実装が
できなかった。
*/

int main()
{
    int n;
    vector<int> a(200005);
    vector<vector<ll>> index(200005);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a.at(i);
    for (int i = 1; i <= n; i++) {
        index.at(a.at(i-1)).push_back(i);
    }
    
    ll maxi = 0;
    for (ll i = 1; i <= n; i++) {
        maxi += (ll)(i/2 * (n-i+1));
    }

    for (int i = 1; i <= n; i++) {
        ll l = 0, r = (ll)index.at(i).size() - 1;
        while (r > l) {
          cout << index.at(i).at(l) << " " << n-index.at(i).at(r) << endl;
            if (index.at(i).at(l) <= n+1-index.at(i).at(r)) {
                maxi -= index.at(i).at(l) * (r - l);
              	l++;
            } else {
              //cout << "a"<< index.at(i).at(r) << endl;
                maxi -= (n+1-index.at(i).at(r)) * (r - l);
            	r--;
            }
         // cout << maxi << endl;
        }
    }

    cout << maxi << endl;

    return 0;
}