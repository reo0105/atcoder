#include<bits/stdc++.h>
using namespace std;


typedef long long ll;

ll extgcd(ll a, ll b, ll &i, ll &j)
{
    if (b == 0) {i = 1; j = 0; return a; }

    ll p = a / b;
    ll g = extgcd(b, a-b*p, j, i);
    j -= p*i;

    return g;
}

int main()
{
    ll x, y;
    cin >> x >> y;
    ll a, b;

    ll g = extgcd(x, y, b, a);

    if (2%g) {
        cout << -1 << endl;
        return 0;
    }

    a *= -2/g;
    b *= 2/g;

    cout << a << " " << b << endl;

    return 0;

}