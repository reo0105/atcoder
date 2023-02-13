#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, int> p;

int main()
{
    int n;
    vector<p> s;

    cin >> n;
    for (int i = 0; i < n; i++) {
        string tmp;
        cin >> tmp;
        s.push_back(make_pair(tmp, i));
    }

    sort(s.begin(), s.end());

    vector<int> a(500005);

    for (int i = 0; i < n; i++) {
        // cout << s.at(i) << endl;
        int ans = 0;
        if (i == 0) {
            int x = min((int)s.at(0).first.size(), (int)s.at(1).first.size());
            for (int j = 0; j < x; j++) {
                if (s.at(0).first.at(j) == s.at(1).first.at(j)) ans++;
                else break;
            }
        } else if (i != n-1) {
            int x = min((int)s.at(i-1).first.size(), (int)s.at(i).first.size());
            for (int j = 0; j < x; j++) {
                if (s.at(i-1).first.at(j) == s.at(i).first.at(j)) ans++;
                else break;
            }

            int tmp = 0;
            x = min((int)s.at(i).first.size(), (int)s.at(i+1).first.size());
            for (int j = 0; j < x; j++) {
                if (s.at(i).first.at(j) == s.at(i+1).first.at(j)) tmp++;
                else break;
            }
            ans = max(ans, tmp);
        } else {
            int x = min((int)s.at(n-2).first.size(), (int)s.at(n-1).first.size());
            for (int j = 0; j < x; j++) {
                if (s.at(n-2).first.at(j) == s.at(n-1).first.at(j)) ans++;
                else break;
            }
        }

        a.at(s.at(i).second) = ans;
    }

    for (int i = 0; i < n; i++) 
        cout << a.at(i) << endl;

    return 0;
}