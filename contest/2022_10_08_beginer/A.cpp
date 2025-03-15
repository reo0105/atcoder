#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, sum = 0;
    vector<int> a(105);

    cin >> n;
    for (int i = 0; i < n; i++) {   
        cin >> a.at(i);
        sum += a.at(i);
    }

    cout << sum << endl;

    return 0;
}