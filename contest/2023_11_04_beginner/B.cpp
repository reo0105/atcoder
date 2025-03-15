#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ll b;
    cin >> b;

    if (b == 1) {
        cout << 1 << endl;
        return 0;
    }

    for (int i = 2; i <= 20; i++) {
        if (b % i == 0) {
            ll temp = b;
            int cnt = 0;
            while (temp != 1) {
                if (temp % i == 0) { temp /= i; cnt++; }
                else break; 
            }

            if (temp == 1 && cnt == i) {
                cout << i << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}