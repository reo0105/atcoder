#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;

int main()
{
    int n;

    cin >> n;

    int cnt  = 0, h = n / 2;

    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s == "For") cnt++;
    }

    if (cnt > h) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}