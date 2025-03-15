#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    int n, t;
    cin >> n >> t;

    set<ll> st;
    st.insert(0);

    vector<ll> score(n, 0);
    map<ll, int> mp;
    mp[0] = n;


    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        a--;

        ll now = score[a];

        mp[now]--;

        if (mp[now] == 0) st.erase(now);

        now += b;

        mp[now] += 1;

        score[a] += b;

        st.insert(now);

        cout << st.size() << endl;

    }

    return 0;
}