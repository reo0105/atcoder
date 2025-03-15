#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b, k;
    cin >> a >> b >> k;

    int cnt = 0;

    while (a < b) {
        a *= k;
        cnt++;
    }

    cout << cnt << endl;

    return 0;
}