#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, k;
    string s, ans = "";
    cin >> n >> k;
    cin >> s;

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(s.at(i) == 'o' && cnt < k) {
            cnt++;
            ans.push_back('o');
        } else {
            ans.push_back('x');
        }
    }
    cout << ans << endl;

    return 0;
}