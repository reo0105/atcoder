#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

#define INF 2e18+5

int main()
{
    int n;
    cin >> n;

    priority_queue<pll, vector<pll>, greater<pll>> que;

    for (int i = 0; i < n; i++) {
        ll t, d;
        cin >> t >> d;
        que.push(make_pair(t, t+d));
    }


    int ans = 0;
    ll now = 0;
    multiset<pll> st;

    while (que.size()) {
        pll top = que.top();
        que.pop();
        ll start = top.first;
        ll end = top.second;
        now = start;

        ll next_start = INF, next_end = INF;
        st.insert(make_pair(end, start));

        while (que.size()) {
            pll top = que.top();
            next_start = top.first;
            next_end = top.second;

            if (start == next_start) {
                st.insert(make_pair(next_end, next_start));
                que.pop();
            } else {
                break;
            }

            if (que.empty()) next_start = INF;
        }

        while (st.size() && now < next_start) {
            auto mini = begin(st);
            st.erase(mini);

            if (now <= (*mini).first) {
                ans++;
                now++;
            }

        }
    }

    cout << ans << endl;

    return 0;
}