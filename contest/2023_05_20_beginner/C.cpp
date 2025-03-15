#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    vector<string> s;

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        s.push_back(tmp);
    }

    sort(s.begin(), s.end());

    do {
        int i;
        for (i = 0; i < n-1; i++) {
            int diff = 0;
            for (int j = 0; j < m; j++) {
                if (s.at(i).at(j) != s.at(i+1).at(j)) diff++;
            }

            if (diff != 1) break;
        }

        if (i == n-1) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(s.begin(), s.end()));

    cout << "No" << endl;

    return 0;
}