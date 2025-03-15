#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAX 1000000000000000001L

ll binary_search(ll a, ll b, ll count)
{
    ll left = -1, right = count;
    ll mid;
    double x, y;

    while (right - left > 1) {
        mid = (left + right) / 2;
        x = (double)a/sqrt(mid);
        y = (double)(a/sqrt(mid+1) + b);
        if (x == y) return mid;
        if (x < y) right = mid;
        else left = mid;
    }

    return mid;
}

int main()
{
    ll a, b;
    ll count = MAX;
    ll t;
    long double ans;

    cin >> a >> b;

    t = binary_search(a, b, count);

    t+=3;
    ans = b*t + a/sqrt(t+1);
    for (int i = 0; i < 6; i++) {
        if (t > 0) {
            t--;
           if (ans > b*t + a/sqrt(t+1)) {
                ans = b*t + a/sqrt(t+1);
// cout << fixed << setprecision(10) << ans << endl;
           }
        }
    }

    cout << fixed << setprecision(12) << ans << endl;


    return 0;
}

int main()
{
    ll a, b;
    ll t;
    long double ans;

    cin >> a >> b;

    t = binary_search(a, b, count);

    t+=3;
    ans = b*t + a/sqrt(t+1);
    for (int i = 0; i < 6; i++) {
        if (t > 0) {
            t--;
           if (ans > b*t + a/sqrt(t+1)) {
                ans = b*t + a/sqrt(t+1);
// cout << fixed << setprecision(10) << ans << endl;
           }
        }
    }

    ll left = -1;
    ll right = MAX;

    while (right - left > 1) {
        int m1 = (left*2+right)/3;
        int m2 = (left+right*2)/3;
        if ((a/sqrt(m1+1)+b) < (a/sqrt(m2+1)+b)) right = m2;
        else left = m1;
    }

    ans = a/sqrt(left+1) + b;

    for (int i = -10; i < 10; i++) {
        if (left+i >= 0) {
            if (ans > a/sqrt(left+i+1) + b*(left+i)) ans = a/sqrt(left+i+1) + b*(left+i);
        }
    }

    cout << fixed << setprecision(12) << ans << endl;


    return 0;
}