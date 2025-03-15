#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MOD 998244353

int main()
{
    ll n;
    cin >> n;

    cout << ((n % MOD) + MOD) % MOD << endl;

    return 0;
}