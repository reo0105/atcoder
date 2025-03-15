#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, w;
    vector<int> a(305);

    set<int> s;

    cin >> n >> w;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
        s.insert(a.at(i));
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            int sum = a.at(i) + a.at(j);
            if (sum <= w) s.insert(sum);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                int sum = a.at(i) + a.at(j) + a.at(k);
                if (sum <= w) s.insert(sum);
            }
        }
    }

    int ans = 0;
    for (int i = 0; i <= w; i++) {
        if (s.count(i)) ans++;
    }

    cout << ans << endl;

    return 0;
}