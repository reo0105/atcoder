#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x;
    cin >> n >> x;
    vector<int> a;

    for (int i = 0; i < n; i++) {
        int tmp;
        cin >> tmp;
        a.push_back(tmp);
    }

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++) {
        int ai = a.at(i);
        int aj = ai-x;

        int tar = *lower_bound(a.begin(), a.end(), aj);

        if (tar == aj) {
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;

    return 0;
} 