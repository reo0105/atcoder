#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<int> p(200005);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> p.at(i);

    int ans = 0;
    int now = 0;

    vector<int> rot(200005, 0);

    for (int i = 0; i < n; i++) {
        int cul = p.at(i);
        int front = (i - cul + n) % n;
        for (int j = -1; j <= 1; j++) {
            rot.at((front+j+n)%n)++;
        }
    }

    for (int i = 0; i < n; i++) ans = max(ans, rot.at(i));

    cout << ans << endl;

    return 0;
}