#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll n, l, w;
    cin >> n >> l >> w;
    vector<ll> a(100005);

    for (int i = 0; i < n; i++) cin >> a.at(i);

    ll now = 0;
    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        ll next = a.at(i);

        if (now < next) {
            cnt += (next - now + w-1) / w;
        }

        now = next+w;
    }

    cnt += (l-now+w-1) / w;

    cout << cnt << endl;

    return 0;
}