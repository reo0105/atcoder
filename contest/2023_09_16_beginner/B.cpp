#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = (int)s.size();

    int ans = 1;
    for (int i = 0; i < n-1; i++) {
        for (int j = i+1; j < n; j++) {
            int l = (j-i) / 2 + 1;
            int k;
            for (k = 0; k < l; k++) {
                if (s[i+k] != s[j-k]) break; 
            }
            if (k == l) {
                ans = max(ans, j-i+1);
            }
        }
    }

    cout << ans << endl;


    return 0;
}