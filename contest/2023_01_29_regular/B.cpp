#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int f(int x, int a, int b)
{
    return abs(abs(x-a)-b);
}

int main()
{
    int q, a1, b1;
    cin >> q >> a1 >> b1;

    set<p> s;
    vector<int> a(200005), b(200005);

    s.insert(make_pair(a1-b1, 0));
    s.insert(make_pair(a1+b1, 0));
    a.at(0) = a1;
    b.at(0) = b1;

    int cnt = 1;
    for (int i = 0; i < q; i++) {
        int t, a0, b0;
        cin >> t >> a0 >> b0;

        if (t == 1) {
            s.insert(make_pair(a0-b0, cnt));
            s.insert(make_pair(a0+b0, cnt));
            a.at(cnt) = a0;
            b.at(cnt) = b0;
            cnt++;
        } else {
            int ans = 1e9;
            auto itr = s.lower_bound(make_pair(a0, -1));
            if (itr != s.end()) {
                if (a0 <= (*itr).first && (*itr).first <= b0){
                    ans = 0;
                } else {
                    // cout << "fir ";
                    ans = min(ans, f(b0, a.at((*itr).second), b.at((*itr).second)));
                    // cout << ans;
                }
            }
            if (itr != s.begin()) {
                itr--;
                if (a0 <= (*itr).first && (*itr).first <= b0){
                    ans = 0;
                } else {
                    // cout << " sec " << a.at((*itr).second) << " " << b.at((*itr).second) << " ";
                    ans = min(ans, f(a0, a.at((*itr).second), b.at((*itr).second)));
                    // cout << ans << " ";
                }
            }

            cout << ans << endl;
        }
    }

    return 0;
}