#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<pii, int> ppi;

int main() {
    int n;
    cin >> n;

    vector<ppi> ac(n);
    for (int i = 0; i < n; i++) {
        cin >> ac[i].first.first >> ac[i].first.second;
        ac[i].second = i;
    }

    sort(ac.begin(), ac.end());
    

    set<int> erase;
    int mini = ac[n-1].first.second;
    for (int i = n-2; i >= 0; i--) {
        if (mini < ac[i].first.second) {
            erase.insert(ac[i].second);
        }
        mini = min(mini, ac[i].first.second);
    }

    cout << n - (int)erase.size() << endl;

    for (int i = 0; i < n; i++) {
        if (!erase.count(i)) {
            cout << i+1 << " ";
        }
    }
    cout << endl;

    return 0;
}