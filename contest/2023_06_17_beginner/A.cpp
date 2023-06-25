#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n >> s;

    for (int i = 0; i < n; i++) {
        cout << s.at(i) << s.at(i);
    }
    cout << endl;

    return 0;
}