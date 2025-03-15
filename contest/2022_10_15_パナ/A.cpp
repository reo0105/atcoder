#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<int> data(12, 1);

    cin >> n;

    for (int i = 1; i < n+1; i++) {
        data.at(i) = i * data.at(i-1);
    }

    cout << data.at(n);

    return 0;
}