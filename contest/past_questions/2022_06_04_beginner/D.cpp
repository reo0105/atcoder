#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    ll cnt = 2;
    vector<ll> a, num(200005);
    cin >> n;

    for (int i = 1; i <= n; i++) num.at(i) = i;

    while (cnt*cnt <= n) {
        a.push_back(cnt*cnt);
        cnt++;
    }

    ll ans = 0;
    for (ll l : a) {
        for (int i = l; i <= n; i += l) {
            while (num.at(i) % l == 0) num.at(i) /= l;
        }
    }

    vector<int> c(200005);
    for (int i = 1; i <= n; i++) c.at(num.at(i))++;

    for (int i = 0; i <= n; i++) ans += c.at(i)*c.at(i);

    cout << ans << endl;


    return 0;
}