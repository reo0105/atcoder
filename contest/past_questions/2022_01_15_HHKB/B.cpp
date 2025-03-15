#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, ans = 0;
    vector<int> h(100005);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> h.at(i);

    for (int i = 0; i < n; i++) {
        if (ans < h.at(i)) {
            ans =  h.at(i);
        } else {
            break;
        }
    }

    cout << ans << endl;
    return 0;
}