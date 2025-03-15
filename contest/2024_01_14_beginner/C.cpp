#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    int d = 1;
    ll five = 5;
    ll sum = 5;

    if (n >= 5){
        while (sum < n) {
            d++;
            sum += five * 4;
            five *= 5;
        }

        five /= 5;
    } else {
        five /= 5;
    }
    n--;

    vector<int> evens = {0, 2, 4, 6, 8};

    for (int i = 0; i < d; i++) {
        int rem = n / five;
        cout << evens[rem];

        n -= rem * five;
        five /= 5;
    }
    cout << endl;
    
    return 0;
}