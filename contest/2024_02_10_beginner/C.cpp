#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
    ll n;
    cin >> n;

    map<ll, ll> mp;
    set<ll> st;

    ll ans = 0;
    st.insert(n);
    mp[n] = 1;

    while (st.size()) {
        ll maxi = *st.rbegin();
        st.erase(maxi);

        if (maxi == 1) break;
        ans += maxi * mp[maxi];

        mp[maxi/2] += mp[maxi];
        mp[(maxi+1)/2] += mp[maxi];

        st.insert(maxi/2);
        st.insert((maxi+1)/2);     
    }

    cout << ans << endl;
    
    return 0;
}