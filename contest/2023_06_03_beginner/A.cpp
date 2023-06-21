#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<string> s(105);
    vector<int> a(105);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> s.at(i) >> a.at(i);

    int mini = 1e9+5;
    int id = -1;
    for (int i = 0; i < n; i++) {
        if (mini > a.at(i)) {
            mini = a.at(i);
            id = i;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << s.at((i+id)%n) << endl;
    }

    return 0;
}