#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
typedef long long ll;

int main()
{
    int n, k;
    vector<int> p(200005);
    vector<int> ans(200005, -1);
    vector<int> under(200005, -1);
    vector<int> cnt(200005, 0);
    set<int> tops;

    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> p.at(i);

    for (int i = 1; i <= n; i++) {
        int now = p.at(i);
        auto itr = tops.lower_bound(now);
        if (itr == tops.end()) {
            tops.insert(now);
            cnt.at(now) = 1;
        } else {
            int top = *itr;
            under.at(now) = top;
            tops.erase(top);
            tops.insert(now);
            cnt.at(now) = cnt.at(top) + 1;
        }

        if (cnt.at(now) == k) {
            tops.erase(now);
            while (under.at(now) != -1) {
                ans.at(now) = i;
                cnt.at(now) = -1;
                now = under.at(now);
            }
            ans.at(now) = i;
        }
    }

    for (int i = 1; i <= n; i++) cout << ans.at(i) << endl;

    return 0;
}