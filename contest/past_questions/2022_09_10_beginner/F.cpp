#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
typedef pair<double, int> pd;
#define INF 1e18

int main()
{
    int n;
    vector<string> s(200005);
    
    cin >> n;
    for (int i = 0; i < n; i++) cin >> s.at(i);

    vector<p> xa;
    vector<pd> xpera;

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        int x = 0;
        int a = 0;
        for (int j = 0; j < (int)s.at(i).size(); j++) {
            if (s.at(i).at(j) == 'X') {
                x++;
                continue;
            }
            ans += x * (s.at(i).at(j) - '0');
            a += s.at(i).at(j) - '0';
        }
        // cout << x << " " << a << endl;
        xa.push_back(make_pair(x, a));
        if (a == 0) xpera.push_back(make_pair((double)INF, i));
        else xpera.push_back(make_pair((double)x/a, i));
    }

    sort(xpera.rbegin(), xpera.rend());
    // for (int i = 0; i < n; i++) cout << xa.at(i).first << " " << xa.at(i).second << endl;
    // for (int i = 0; i < n; i++) cout << xpera.at(i).first << " " << xpera.at(i).second << endl;
    // cout << ans << endl;

    int id = xpera.at(0).second;
    int x = xa.at(id).first;
    for (int i = 1; i < n; i++) {
        id = xpera.at(i).second;
        ans += (ll)x * xa.at(id).second;
        x += xa.at(id).first; 
    }

    cout << ans << endl;

    return 0;
}