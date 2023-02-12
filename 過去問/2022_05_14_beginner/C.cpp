#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    set<string> ss;
    set<int> st;

    cin >> n;

    int ans = 0, score = 0;
    for (int i = 0; i < n; i++) {
        string s;
        int t;
        cin >> s >> t;

        if (!ss.count(s)) {
            ss.insert(s);
            if (t > score) {
                score = t;
                ans = i + 1;
            }
        }
    }

    cout << ans << endl;


}