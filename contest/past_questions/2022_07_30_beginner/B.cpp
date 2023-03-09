#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, a, b;
    cin >> n >> a >> b;

    ll rem = n % a;
    ll round = n/a;

    // cout << rem << endl;
    // cout << round*a+b-1-n << endl;
    // cout << b -rem << endl;
    ll ans = b * (round-1) + min(rem+1, b);// - (a-1);
    if (a <= b) ans = max(0LL, n-(a-1));
    if (round == 0) ans = 0LL;

    ans = max(0LL, ans);

    cout << ans << endl;

    return 0;
}

// 10752507242
// 10752495144
//       12102