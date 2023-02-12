#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    vector<int> a(200005); //各インデックスに何があるか
    vector<int> pos(200005); //各数がどこにあるか

    cin >> n >> q;

    for (int i = 1; i <= n; i++) {
        a.at(i) = i;
        pos.at(i) = i;
    }

    for (int i = 0; i < q; i++) {
        int x, index0, index1, num;
        cin >> x;
        index0 = pos.at(x);
        index1 = (index0 == n) ? index0-1 : index0+1;
        num = a.at(index1);
        swap(a.at(index0), a.at(index1));
        swap(pos.at(x), pos.at(num));
    }

    for (int i = 1; i <= n; i++) cout << a.at(i) << " ";
    cout << endl;

    return 0;
}