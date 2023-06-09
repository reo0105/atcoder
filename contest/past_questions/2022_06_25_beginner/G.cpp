#include <bits/stdc++.h>
using namespace std;

vector<int> z_algorithm(string s)
{
    int c = 0, n = (int)s.size();
    vector<int> z(n, 0);

    for (int i = 1; i < n; i++) {
        int l = i - c;
        
        if (i + z[l] < c + z[c]) {
            z[i] = z[l];
        } else {
            int j = max(0, c+z[c]-i);

            while (i+j < n && s[j] == s[i+j]) j++;

            z[i] = j;
            c = i;
        }
    }

    z[0] = n;
    return z;
}


int main()
{
    string s, t;
    string x;

    cin >> s >> t;
    x = s + '$' + t;

    vector<int> z = z_algorithm(x);

    // for (int a : z) cout << a << " ";
    // cout << endl;

    int m = s.size();
    int n = t.size();
    int r = 0, i = 0;
    int ans = 0;
    while (r < n) {
        int nr = r;
        while (i <= r) {
            nr = max(nr, i+z[m+1+i]);
            i++;
        }
        if (nr == r) { cout << -1 << endl; return 0;}
        // cout << i << " " << r << " " << nr << endl;
        r = nr;
        ans++;
    } 
    cout << ans << endl;
    return 0;
}