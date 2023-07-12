#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    

    vector<string> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == 0) {
                if (j == 0) cout << a.at(1).at(0);
                else cout << a.at(0).at(j-1);
            } else if (i == n-1) {
                if (j != n-1) cout << a.at(i).at(j+1);
                else cout << a.at(i-1).at(j);
            } else {
                if (j == 0) cout << a.at(i+1).at(j);
                else if (j != n-1) cout << a.at(i).at(j);
                else cout << a.at(i-1).at(j);
            }
        }
        cout << endl;
    }
}