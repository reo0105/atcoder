#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n, q;
    string s;

    cin >> n >> q;
    cin >> s;

    vector<int> adj(n, 0);

    for (int i = 1; i < n; i++) {
        adj[i] = adj[i-1];
        if (s[i-1] == s[i]) adj[i]++;
    }

    ll ans = 0;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--; r--;
        cout << adj[r] - adj[l] << endl;
    }


    return 0;
}