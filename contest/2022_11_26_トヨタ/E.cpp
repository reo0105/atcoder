#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, pos = 1;
    vector<int> a(200002);
    vector<int> b(200002);
    vector<int> index(200002);
    map<int, int> ma;

    cin >> n >> m;

    for (int i = 1; i <= m; i++) cin >> a.at(i);
    for (int i = 1; i <= n; i++) b.at(i) = i;

    for (int i = 1; i <= m; i++) {
        if (b.at(a.at(i)) == 1) {
            index.at(i) = b.at(a.at(i)+1);
            pos = a.at(i) + 1;
        } else if (b.at(a.at(i)+1) == 1) {
            index.at(i) = b.at(a.at(i));
            pos = a.at(i);
        } else {
            index.at(i) = 1;
        }
        swap(b.at(a.at(i)), b.at(a.at(i)+1));
    }

    for (int i = 1; i <= n; i++) {
        ma[b.at(i)] = i;
    }

    for (int i = 1; i <= m; i++) {
        cout << ma[index.at(i)] << endl;
    }

    return 0;

}