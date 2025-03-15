#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n, k;
    vector<string> s;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        string str;
        cin >> str;
        if (i < k) {
            s.push_back(str);
        }
    }

    sort(s.begin(), s.end());

    for (int i = 0; i < k; i++) cout << s.at(i) << endl;

    return 0;
}