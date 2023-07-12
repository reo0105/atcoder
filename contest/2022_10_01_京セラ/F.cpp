#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n;
    vector<vector<int>> a(25, vector<int>(25));

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a.at(i).at(j);
        }
    }

    vector<vector<int>> msa(22), msb(22);

    for (int s = 0; s < (1<<(n-1)); s++) {
        int nx = 0, ny = 0;
        int num = a.at(nx).at(ny);
        for (int i = 0; i < (n-1); i++) {
            if ((s>>i) & 1) {
                ny++;
                num ^= a.at(nx).at(ny);
            } else {
                nx++;
                num ^= a.at(nx).at(ny);
            }
        }

        msa.at(nx).push_back(num);
    }

    for (int s = 0; s < (1<<(n-1)); s++) {
        int nx = n-1, ny = n-1;
        int num = a.at(nx).at(ny);
        for (int i = 0; i < (n-1); i++) {
            if ((s>>i) & 1) {
                ny--;
                num ^= a.at(nx).at(ny);
            } else {
                nx--;
                num ^= a.at(nx).at(ny);
            }
        }

        msb.at(nx).push_back(num);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)msa.at(i).size(); j++) {
            msa.at(i).at(j) ^= a.at(i).at(n-1-i);
        }
    }

    for (int i = 0; i < n; i++) sort(msb.at(i).begin(), msb.at(i).end());

    ll ans = 0;
    for (int i = 0; i < n; i++) {
        for (int x : msa.at(i)) {
            ans += upper_bound(msb.at(i).begin(), msb.at(i).end(), x) - lower_bound(msb.at(i).begin(), msb.at(i).end(), x);
            // ans += msb.at(i).count(x);
        }
    }

    cout << ans << endl;

    return 0;
}
