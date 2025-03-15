#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<bitset<3005>> G(3005);

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) {
            if (s.at(j) == '1') G.at(i).set(j);
        }
    }

    ll cnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (G.at(i).test(j)) {
                cnt += (G.at(i) & G.at(j)).count();
            }
        }
    }

    cout << cnt / 3 << endl;

    return 0;
}