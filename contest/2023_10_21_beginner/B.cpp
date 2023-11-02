#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main()
{
    int n;
    cin >> n;

    vector<pii> wx(n);
    for (int i = 0 ; i < n; i++) {
        cin >> wx[i].second >> wx[i].first;
    }

    sort(wx.begin(), wx.end());

    for (int i = 0; i < n; i++) {
        if (wx[i].first < 10) {
            wx.push_back(make_pair(wx[i].first+24, wx[i].second));
        }
    }

    int ans = 0;
    int temp = wx[0].second;

    int r = 1;
    n = (int)wx.size();
    for (int l = 0; l < n; l++) {
        while (wx[r].first - wx[l].first <= 8 && r < n) {
            temp += wx[r].second;
            r++;
        }
        
        ans = max(ans, temp);
        if (l == r) r++;
        temp -= wx[l].second;
    }

    cout << ans << endl;

    return 0;
}