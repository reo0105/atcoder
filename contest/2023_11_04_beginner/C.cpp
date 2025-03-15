#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    vector<vector<int>> a(9, vector<int>(9));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cin >> a[i][j];
        }
    }

    int ok = 1;

    for (int i = 0; i < 9; i++) {
        set<int> st;
        for (int j = 0; j < 9; j++) {
            st.insert(a[i][j]);
        }
        if ((int)st.size() != 9) ok = 0;
    }

    for (int i = 0; i < 9; i++) {
        set<int> st;
        for (int j = 0; j < 9; j++) {
            st.insert(a[j][i]);
        }
        if ((int)st.size() != 9) ok = 0;
    }

    vector<int> dir_x = {0, 1, 2, 0, 1, 2, 0, 1, 2};
    vector<int> dir_y = {0, 0, 0, 1, 1, 1, 2, 2, 2};

    for (int i = 0; i < 9; i++) {
        set<int> st;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                st.insert(a[j+dir_y[i]*3][k+dir_x[i]*3]);
            }
        }

        if ((int)st.size() != 9) ok = 0;
    }

    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}