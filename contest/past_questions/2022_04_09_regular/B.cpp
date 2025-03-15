#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, fi = -1, bi = -1;
    vector<int> a(200005);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a.at(i);
    }

    int flag = 1, flip = 0;
    int b = 0, e = n-1;

    for (int i = 0; i < n; i++) {
        if ((a.at(e) == 0 && flip % 2 == 0) || (a.at(e) == 1 && flip % 2 == 1)) {
            e--;
        } else {
            if ((a.at(b) == 0 && flip % 2 == 0) || (a.at(b) == 1 && flip % 2 == 1)) { b++; flip++; }
            else {flag = 0; break;}
        }
    }

    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}