#include <bits/stddc++.h>
using namespace std;
typedef long long ll;
typedef pair<bool, ll> p;

int main()
{
    int n;
    vector<int> a(300005);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a.at(i);

    vector<ll> dp0(300005, 1L<<58);

    dp0.at(1) = make_pair(true, a.at(i));
    dp0.at(0) = make_pair(false, 0);
    dp0.at(1) = make_pair(true, 1);

    for (int i = 2; i <= n; i++) {
        bool mv = dp0.at(i-1).first;
        if (mv) {
            dp0.at(i) = 
        } else {
            dp0.at(i) = min(dp0.at(i-1), dp0.at(i-2) + a.at(i));
        }
    }
}