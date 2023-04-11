#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1e18

int main()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a.at(i);
    sort(a.begin(), a.end());

    priority_queue<ll, vector<ll>, greater<ll>> que;
    set<ll> st;

    que.push(0);
    
    for (int i = 1; i <= k; i++) {
        ll top = que.top();
        que.pop();

        for (int j = 0 ; j < n; j++) {
            ll next = top + a.at(j);
            if (!st.count(next)) {
                st.insert(next);
                que.push(next);
            }
        }
    }

    ll next;
    for (int i = 1; i <= k; i++) {
        next = *begin(st);
        st.erase(next);
    }
    cout << next << endl;

    return 0;
}