#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    multiset<int> a, b;
    vector<int> va(5005), vb(5005);
    int flag = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (a.count(x)) flag = 1;
        a.insert(x);
        va.at(i) = x;
    }
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        b.insert(x);
        vb.at(i) = x;
    }

    if (a != b) {
        cout << "No" << endl;
    } else {
        int cnta = 0, cntb = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (va.at(i) > va.at(j)) cnta++;
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                if (vb.at(i) > vb.at(j)) cntb++;
            }
        }

        if (cnta%2 == cntb%2 || flag) cout << "Yes" << endl;
        else cout << "No" << endl;
    }

    return 0;
}