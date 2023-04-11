#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    ll a, b;
    cin >> a >> b;

    ll g = gcd(a, b);

    a /= g;
    b /= g;

    if (a > b) swap(a, b);
    ll diff = b-a;

    vector<int> t;
    for (int i = 1; i*i <= diff; i++) {
        if (diff % i != 0) continue;

        t.push_back(i);

        if (diff / i != i) t.push_back(diff/i);
    }

    int sz = (int)t.size();
    sort(t.begin(), t.end());

    int cnt = 0;
    if (a == b) {
        cnt = 1;
    } else {
        while (a > 0) {
            for (int i = sz-1; i >= 0; i--) {
                if ((g = gcd(a-t.at(i), b-t.at(i))) != 1) {
                    // int num = a / t.at(i);
                    cnt++;
                    a -= t.at(i)*g;
                    b -= t.at(i)*g;
                    // break;
                }
            }
        }
    }
    

    // for (int i = 0; i < sz; i++) cout << t.at(i) << " ";


    cout << cnt << endl;

    return 0;
}

