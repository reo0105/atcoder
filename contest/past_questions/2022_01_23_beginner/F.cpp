#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

int main()
{
    int n;
    vector<p> c;

    cin >> n;
    for (int i = 1; i <= (1<<n)-1; i++) {
        int a;
        cin >> a;
        c.push_back(make_pair(a, i));
    }

    sort(c.begin(), c.end());

    ll ans = 0;
    vector<int> bases(20, 0);
    for (auto p : c) {
        int c = p.first;
        int x = p.second;

        for (int i = 0; i < n; i++) {
            if ((x>>i)&1) x ^= bases[i];
        }

        if (x == 0) continue;
        ans += c;

        for (int i = 0; i < n; i++) {
            if ((x>>i)&1) {
                bases[i] = x;
                for (int j = 0; j < n; j++) {
                    if (j != i && (bases[j]>>i)&1) {
                        bases[j] ^= x;
                    }
                }
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}