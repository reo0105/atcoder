#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;

    vector<int> is(200005);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        is.at(p) = i;
    }

    vector<int> now(200005, 0);
    vector<int> inc(200005, 0);
    vector<int> dec(200005, 0);
    int de = 0, in = 0;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int p = is.at(i);
        now.at(i) = min((p-i+n)%n, (i-p+n)%n);
        ans += now.at(i);
        int next = min((((p+1)%n)-i+n)%n, (i-((p+1)%n)+n)%n);
        if (now.at(i) > next) { dec.at(now.at(i))++; de++; }
        else { inc.at(now.at(i))++; in++; }
    }

    // cout << de << " " << in << endl;

    // for (int i = 0; i < n; i++) cout << dec.at(i) << " ";
    // cout << endl;
    // for (int i = 0; i < n; i++) cout << inc.at(i) << " ";
    // cout << endl;

    // cout << ans << endl;
    ll t = ans;
    cout << t << endl;
    if (n % 2 == 0) {
        for (int cnt = 1; cnt < n; cnt++) {
            // cout << ans << endl;
            // cout << de << " " << in << endl; 
            if (cnt <= n/2) {
                t = t+in-de;
                cout << t << endl;
                ans = min(ans, t);
                in += dec.at(cnt);
                in -= inc.at(n/2-cnt);
                de += inc.at(n/2-cnt);
                de -= dec.at(cnt);
            } else {
                t = t+in-de;
                cout << t << endl;
                ans = min(ans, t);
                in += dec.at(n-cnt);
                in -= inc.at(n/2-cnt);
                de += inc.at(n/2-cnt);
                de -= dec.at(cnt);
            }
        }

        cout << ans << endl;
    } else {
        for (int cnt = 1; cnt < n; cnt++) {
            // cout << ans << endl;
            ans = min(ans, ans+in-de);
            in += dec.at(cnt);
            in -= inc.at(n/2-cnt);
            de += inc.at(n/2-cnt);
            de -= dec.at(cnt);
        }
    }

}