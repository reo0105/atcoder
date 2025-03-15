#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    int n, t;
    cin >> n >> t;

    vector<ll> points(n+5, 0);
    map<ll, int> mp;
    set<ll> st;

    st.insert(0);
    mp[0] = n;

    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;

        ll now = points[a];
        mp[now]--;
        if (mp[now] == 0) {
            st.erase(now);
        }

        now += b;
        points[a] = now;
        mp[now]++;
        st.insert(now);

        cout << st.size() << endl;
    }

}