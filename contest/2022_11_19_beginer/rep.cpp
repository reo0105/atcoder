#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int H, W, n, h, w;
    cin >> H >> W >> n >> h >> w;

    vector<int> mini(305, H+1);
    vector<int> maxi(305, 0);
    vector<int> minj(305, W+1);
    vector<int> maxj(305, 0);

    for (int i = 1; i <= H; i++) {
        for (int j = 1; j <= W; j++) {
            int a;
            cin >> a;
            a -= 1;
            mini.at(a) = min(mini.at(a), i); 
            maxi.at(a) = max(maxi.at(a), i); 
            minj.at(a) = min(minj.at(a), j); 
            maxj.at(a) = max(maxj.at(a), j); 
        }
    }

    for (int i = 0; i <= H-h; i++) {
        for (int j = 0; j <= W-w; j++) {
            int k = i+h, l = j+w, ans = n;
            for (int a = 0; a < n; a++) {
                if (i < mini.at(a) && maxi.at(a) <= k && j < minj.at(a) && maxj.at(a) <= l) {
                    ans--;
                    // cout << a << " ";
                }
            }
            if (j != W-w) cout << ans << " ";
            else cout << ans << endl;
        }
    }

    return 0;
}