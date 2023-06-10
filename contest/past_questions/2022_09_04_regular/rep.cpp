#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

int main()
{
    int n;
    vector<int> p(405);
    vector<pi> ans;

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p.at(i);

    for (int i = 1; i <= n; i++) {
        if (p.at(i) % 2 && i % 2 == 0) {
            int t = i;
            while (1) {
                t = t-2;
                if (t >= 1 && p.at(t) % 2 == 0) {
                    ans.push_back(make_pair(1, t));
                    swap(p.at(t), p.at(t+2));
                } else break;
            }
        } else if (p.at(i) % 2 == 0 && i % 2) {
            int t = i;
            while (1) {
                t = t-2;
                if (t >= 1 && p.at(t) % 2) {
                    ans.push_back(make_pair(1, t));
                    swap(p.at(t), p.at(t+2));
                } else break;
            }
        }
    }

    for (int i = 1; i <= n; i += 2) {
        if (p.at(i) % 2 == 0) {
            ans.push_back(make_pair(0, i));
            swap(p.at(i), p.at(i+1));
        }
    }

    int s = (n % 2) ? n : n-1;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= 3; j -= 2) {
            if (p.at(j-2) > p.at(j)) {
                ans.push_back(make_pair(1, j-2));
                swap(p.at(j-2), p.at(j));
            }
        }
    }

    s = (n % 2) ? n-1 : n;
    for (int i = 1; i <= n; i++) {
        for (int j = s; j >= 3; j -= 2) {
            if (p.at(j-2) > p.at(j)) {
                ans.push_back(make_pair(1, j-2));
                swap(p.at(j-2), p.at(j));
            }
        }
    }

    // for (int i = 1; i <= n; i++) cout << p.at(i) << " ";
    // cout << endl;

    cout << ans.size() << endl;
    for (int i = 0; i < (int)ans.size(); i++) {
        if (ans.at(i).first) cout << "B " << ans.at(i).second << endl;
        else cout << "A " << ans.at(i).second << endl;
    }        

    return 0;
}