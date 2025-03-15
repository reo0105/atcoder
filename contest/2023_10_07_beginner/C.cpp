#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(m);
    for (int i = 0; i < m; i++) cin >> a[i];

    vector<int> point(n, 0);
    vector<vector<int>> rems(n);

    int maxi = 0;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'o') point[i] += a[j];
            else rems[i].push_back(a[j]);
        }
        point[i] += i+1;
        maxi = max(maxi, point[i]);
        sort(rems[i].rbegin(), rems[i].rend());
    }

    for (int i = 0; i < n; i++) {
        int cnt = 0;
        int now = point[i];
        while (maxi > now) {
            now += rems[i][cnt];
            cnt++;
        }

        cout << cnt << endl;
    }

    return 0;
}