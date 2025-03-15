#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<bool> is_prime(1000005, true);
vector<int> primes;
vector<int> s(1000005, 0);


void Eratosthenes()
{
    is_prime.at(0) = false;
    is_prime.at(1) = false;

    for (int i = 2; i <= 1000002; i++) {
        if (is_prime.at(i)) {
            primes.push_back(i);
            for (int j = i*2; j < 1000002; j += i) {
                is_prime.at(j) = false;
            }
        }
    }
}

int main()
{
    ll n;
    ll ans = 0;//, flag = 1;

    cin >> n;
    Eratosthenes();
    // for (int p : primes) {
    //     s.at(p) = 1;
    //     // cout << p << " ";
    // }
    // for (int i = 1; i < 1000002; i++) s.at(i+1) += s.at(i);

    for (int i = 3; i < 1000002; i++) {
        if (is_prime.at(i)) {
            ll q = (ll)i*i*i;
            if (q > n) break;
            for (int j = 2; j < i; j++) {
                if (is_prime.at(j)) {
                    if (j <= n/q) ans++;
                    else break;
                } else if (n / q < j) break;                
            }
        }
    }

    // for (int q : primes) {
    //     int p = min<ll>(n/q/q/q, q-1);
    //     // cout << p << " " << q << endl;
    //     ans += s.at(p);
    // }

    cout << ans << endl;

    return 0;
}