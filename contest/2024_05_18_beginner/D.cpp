#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main() {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;

    const int m = 1e9;

    a += m;
    b += m;
    c += m;
    d += m;

    ll diff_i = d-b;
    ll diff_j = c-a;

    ll four = diff_j / 4 * 4;
    ll ans = four * diff_i / 2;
    
    ans *= 2;

    ll tmp = 0;

    if (diff_j % 4 == 1) {
        if (a % 4 == 0) tmp = 3;
        else if (a % 4 == 1) tmp = 3;
        else if (a % 4 == 2) tmp = 1;
        else if (a % 4 == 3) tmp = 1;
    } else if (diff_j % 4 == 2) {
        if (a % 4 == 0) tmp = 6;
        else if (a % 4 == 1) tmp = 4;
        else if (a % 4 == 2) tmp = 2;
        else if (a % 4 == 3) tmp = 4;
    } else if (diff_j % 4 == 3) {
        if (a % 4 == 0) tmp = 7;
        else if (a % 4 == 1) tmp = 5;
        else if (a % 4 == 2) tmp = 5;
        else if (a % 4 == 3) tmp = 7;
    }

    tmp *= diff_i / 2;
    ans += tmp;

    if (diff_i % 2) {
        if (b % 2 == 0) {
            if (diff_j % 4 == 1) {
                if (a % 4 == 0) ans += 2;
                else if (a % 4 == 1) ans += 1;
                else if (a % 4 == 2) ans += 0;
                else if (a % 4 == 3) ans += 1;
            } else if (diff_j % 4 == 2) {
                if (a % 4 == 0) ans += 3;
                else if (a % 4 == 1) ans += 1;
                else if (a % 4 == 2) ans += 1;
                else if (a % 4 == 3) ans += 3;
            } else if (diff_j % 4 == 3) {
                if (a % 4 == 0) ans += 3;
                else if (a % 4 == 1) ans += 2;
                else if (a % 4 == 2) ans += 3;
                else if (a % 4 == 3) ans += 4;
            }
        } else {
            if (diff_j % 4 == 1) {
                if (a % 4 == 0) ans += 1;
                else if (a % 4 == 1) ans += 2;
                else if (a % 4 == 2) ans += 1;
                else if (a % 4 == 3) ans += 0;
            } else if (diff_j % 4 == 2) {
                if (a % 4 == 0) ans += 3;
                else if (a % 4 == 1) ans += 3;
                else if (a % 4 == 2) ans += 1;
                else if (a % 4 == 3) ans += 1;
            } else if (diff_j % 4 == 3) {
                if (a % 4 == 0) ans += 4;
                else if (a % 4 == 1) ans += 3;
                else if (a % 4 == 2) ans += 2;
                else if (a % 4 == 3) ans += 3;
            }
        }
    }


    cout << ans << endl;

    return 0;
}