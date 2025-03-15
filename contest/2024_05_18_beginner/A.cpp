#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    int h;
    cin >> h;

    int two = 1;

    int ans = 0;
    int sum = 0;
    while (h >= sum) {
        sum += two;
        two *= 2;
        ans++;
    }

    cout << ans << endl;


    return 0;
}