#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<vector<int>> a(105, vector<int>(105, 0));
    vector<vector<int>> b(105, vector<int>(105, 0));

    int ones = 0;
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a.at(i).at(j);
            if (a.at(i).at(j) == 1) ones++;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> b.at(i).at(j);
        }
    }

    vector<vector<int>> tmp(105, vector<int>(105, 0));

    for (int k = 0; k < 4; k++) {
        for (int j = 0; j < n; j++) {
            for (int i = n; i > 0; i--) {
                tmp.at(j).at(n-i) = a.at(i-1).at(j);
            }
        }

        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         cout << tmp.at(i).at(j) <<" ";
        //     }
        //     cout << endl;
        // }
        // cout << endl;

        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (tmp.at(i).at(j) == 1 && b.at(i).at(j) == 1) cnt++;
            }
        }
        // cout << cnt << " " << ones << endl; 

        if (cnt == ones) {
            cout << "Yes" << endl;
            return 0;
        } else {
            swap(tmp, a);
        }
    }

    cout << "No" << endl;

    return 0;
}