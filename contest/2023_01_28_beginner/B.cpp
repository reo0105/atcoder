#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int n, m;
    vector<string> s(1005), t(1005);

    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s.at(i);
    for (int i = 0; i < m; i++) cin >> t.at(i);

    int ans = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int cnt = 0;
            for (int k = 0; k < 3; k++) {
                if (s.at(i).at(k+3) == t.at(j).at(k)) cnt++;
            }
            if (cnt == 3) {
                ans ++; 
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}