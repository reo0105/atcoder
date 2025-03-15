#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for (int i = 0; i < n; i++) a[i] = i+1;

    l--; r--;
    for (int i = 0; i <= (r-l)/2; i++) swap(a[l+i], a[r-i]);

    for (int i = 0; i < n; i++) cout << a[i] << " ";

    cout << endl;
    return 0;
}