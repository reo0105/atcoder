#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    cin >> n;
    
    vector<int> a;
    for (int i = 0; i < n; i++) {
        int t;
        cin >> t;
        a.push_back(t);
    }

    sort(a.begin(), a.end());

    vector<int> per = {0, 1, 2};
    vector<string> s(3);
    s.at(0) = to_string(a.at(n-1));
    s.at(1) = to_string(a.at(n-2));
    s.at(2) = to_string(a.at(n-3));

    ll ans = 0;
    do {
        string t;
        for (int i = 0; i < 3; i++) {
            t.append(s.at(per.at(i)));
        }
        ans = max(ans, stoll(t));
    } while(next_permutation(per.begin(), per.end()));

    cout << ans << endl;

    return 0;
}