#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<string> s(12);

    cin >> n;

    for (int i = 0; i < n; i++) cin >> s.at(i);

    for (int i = n-1; i >= 0; i--) {
        cout << s.at(i) << endl;
    }

    return 0;
}