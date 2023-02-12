#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

map<ll, ll> fs;


ll f(ll x) 
{
    ll fx;
    if (!fs.count(x)) {
        fx = f(x/2) + f(x/3);
        fs[x] = fx;
    }
    
    return fs[x];
}


int main()
{
    ll n;
    ll ans = 0;

    cin >> n;

    fs[0] = 1;

    f(n);

    ans = fs[n];

    cout << ans << endl;

    return 0;
}