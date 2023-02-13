#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// vector<bool> isprime(10000000, true);
// void Eratosthenes (int n)
// {
    
//     isprime.at(0) = false;
//     isprime.at(1) = false;

//     for (int i = 2; i*i <= n; i++) {
//         if (isprime.at(i)) {
//             for (int j = 2; i*j <= n; j++) {
//                 isprime.at(i*j) = false;
//             }
//         }
//     }
// }


int main()
{
    int t;
    cin >> t;
    // vector<bool> isprime(10000000, true);

    // Eratosthenes(10000000);

    for (int i = 0; i < t; i++) {
        unsigned long n, p;
        cin >> n;
        for (p = 2; p * p <= n; p++) {
            if (n % p == 0) break;
        }

        if ((n / p) % p == 0) {
            cout << p << " " << ((n / p) / p) << endl;
        } else {
            ll q = sqrtl(n/p);
            cout << q << " " << p << endl;
        }
    }

    return 0;
}