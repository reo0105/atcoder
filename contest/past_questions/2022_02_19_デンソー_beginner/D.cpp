#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;

    vector<bool> isprime(205, true);
    
    isprime.at(0) = false;
    isprime.at(1) = false;

    for (int i = 2; i*i < 205; i++) {
        if (isprime.at(i)) {
            for (int j = 2; i*j < 205; j++) {
                isprime.at(i*j) = false;
            }
        }
    }


    int cnt = 0;
    for (int i = a; i <= b; i++) {
        for (int j = c; j <= d; j++) {
            if (isprime.at(i+j)) {
                cnt++;
                break;
            }
        }
    }

    if (cnt == (b-a+1)) cout << "Aoki" << endl;
    else cout << "Takahashi" << endl;

    return 0;
}