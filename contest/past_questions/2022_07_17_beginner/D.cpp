#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int n, k;
    vector<int> under(200005, 0);
    vector<int> cnt(200005, 0);
    vector<int> ans(200005, -1);
    set<int> s;

    cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        auto itr = s.lower_bound(x);
        if (itr == s.end()) {
            s.insert(x);
            cnt.at(x) = 1;
        } else {
            int num = *itr;
            s.erase(num);
            s.insert(x);
            // cout << num << " : " << *itr << endl;
            cnt.at(x) = cnt.at(num) + 1;
            // cout << x << " " << cnt.at(x) << endl;
            under.at(x) = num;
        }

        if (cnt.at(x) >= k) {
            s.erase(x);
            for (int j = 0; j < k; j++) {
                ans.at(x) = i;
                x = under.at(x);
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        cout << ans.at(i) << endl;
    }


    return 0;
}