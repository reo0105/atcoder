#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll x;
    set<ll> exi;

    cin >> x;

    for (int fir = 1; fir <= 9; fir++) {
        for (int diff = -9; diff < 9; diff++) {
            string s;
            int num = fir;
            for (int i = 0; i < 18; i++) {
                s.push_back(num+'0');
                exi.insert(stoll(s));
                num += diff;
                if (!(0 <= num && num <= 9)) break;
            }
        }
    }

    cout << *exi.lower_bound(x) << endl;


    return 0;
}