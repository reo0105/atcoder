#include <bits/stdc++.h>
using namespace std;

void Eratosthenes (int n)
{
    vector<bool> isprime(n, true);
    
    isprime.at(0) = false;
    isprime.at(1) = false;

    for (int i = 2; i*i <= n; i++) {
        if (isprime.at(i)) {
            for (int j = 2; i*j <= n; j++) {
                isprime.at(i*j) = false;
            }
        }
    }
}

typedef long long ll;
vector<pair<ll, ll>> prime_factorize(ll n)
{
    vector<pair<ll, ll> > res;

    for (ll p = 2; p * p <= n; p++) {
        if (n % p != 0) continue;

        int e = 0;
        while(n % p == 0) {
            e++;

            n /= p;
        }

        res.emplace_back(p, e);
    }

    if (n != 1) {
        res.emplace_back(n, 1);
    }

    return res;
}

int main()
{
    ll k, ans = 0, t, cnt, c=0;
    vector<pair<ll, ll> > res;
    cin >> k;

    res = prime_factorize(k);

    for (int j = 0; j < res.size(); j++) {
        t = res.at(j).first;
        cnt = t;
        c = 2;
        for (int i = 0; i < res.at(j).second; i++) {
            if (cnt % t != 0) {
                cnt = t*c;
                c++;
            } 
            if (ans < cnt) ans = cnt;
            cnt /= t;
        }
    }

    cout << ans << endl;

    return 0;
}