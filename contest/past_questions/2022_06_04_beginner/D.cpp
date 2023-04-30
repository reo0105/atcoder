#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n;
    ll cnt = 2;
    vector<ll> a, num(200005);
    cin >> n;

    for (int i = 1; i <= n; i++) num.at(i) = i; //nまでの数を用意

    while (cnt*cnt <= n) {
        a.push_back(cnt*cnt); //n以下の平方数を用意
        cnt++;
    }

    ll ans = 0;
    for (ll l : a) {
        for (int i = l; i <= n; i += l) {
            while (num.at(i) % l == 0) num.at(i) /= l; //各数を平方数で割れるだけ割っていく
        }
    }

    vector<int> c(200005);
    for (int i = 1; i <= n; i++) c.at(num.at(i))++; //そうやって残った素因数をグループ化

    for (int i = 0; i <= n; i++) ans += c.at(i)*c.at(i);//同じグループのサイズの席の和が答え

    cout << ans << endl;


    return 0;
}