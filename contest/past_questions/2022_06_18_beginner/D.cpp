#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;

int main()
{
    int n;
    vector<int> cnt(200005, 0);
    cin >> n;

    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        cnt.at(l)++;
        cnt.at(r)--;
    }


    int l = -1, r = -1, t = 0;
    for (int i = 1; i < 200005; i++) {
        if (l == -1 && cnt.at(i) != 0) {
            l = i;
            t += cnt.at(i);
        } else if (cnt.at(i) != 0) {
            t += cnt.at(i);
        }

        if (l != -1 && t == 0) {
            r = i;
            cout << l << " " << r << endl;
            l = -1;
        }
    }

    // for (int i = 1; i < 200005; i++) cnt.at(i) += cnt.at(i-1);
    // for (int i = 1; i < 200005; i++) {
    //     if (cnt.at(i-1) == 0 && cnt.at(i) != 0) cout << i << " ";
    //     if (cnt.at(i-1) != 0 && cnt.at(i) == 0) cout << i << endl;
    // }

    return 0;
}
