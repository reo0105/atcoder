#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(200005);
    multiset<int> head_k, back;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        if (i < m) back.insert(a.at(i));
    }

    ll ans = 0;
    for (int i = 0; i < k; i++) {
        int mini = *begin(back);
        back.erase(back.find(mini));
        head_k.insert(mini);
        ans += mini;
    }

    cout << ans << endl;

    if (k == m) {
        for (int i = m; i < n; i++) {
            int next = a.at(i);
            int out = a.at(i-m);

            ans += next - out;
            cout << ans << endl;
        }
        return 0;
    }

    for (int i = m; i < n; i++) {
        int next = a.at(i);
        int out = a.at(i-m);

        if (*rbegin(head_k) >= out) {
            head_k.erase(head_k.find(out));
            int mini = *begin(back);
            head_k.insert(mini);
            back.erase(back.find(mini));

            ans += mini - out;
        } else {
            back.erase(back.find(out));
        }

        back.insert(next);

        if (*begin(back) < *rbegin(head_k)) {
            int mini = *begin(back);
            back.erase(back.find(mini));
            head_k.insert(mini);

            int maxi = *rbegin(head_k);
            head_k.erase(head_k.find(maxi));
            back.insert(maxi);

            ans += mini - maxi;
        }

        cout << ans << endl;
    }

    return 0;
}