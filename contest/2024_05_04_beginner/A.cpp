#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, x, y, z;
    cin >> n >> x >> y >> z;

    if (x > y) swap(x, y); 
    // cout << x << " " << z << " " << y << endl; 
    if (x <= z && z <= y) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}