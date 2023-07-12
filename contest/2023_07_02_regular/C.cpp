#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++) {
        int n;
        cin >> n;

        if (n == 1) cout << "Yes\n1\n";
        else if (n == 2) cout << "No\n";
        else {
            set<int> done;
            done.insert(2);
            done.insert(3);
            done.insert(6);
            for (int i = 0; i < n-3; i++) {
                for (int k : done) {
                    if ((ll)k*(k+1) <= 1e9 && !done.count(k+1) && !done.count((k*(k+1)))) {
                        done.insert(k+1);
                        done.insert(k*(k+1));
                        done.erase(k);
                        break;
                    }
                }
            }

            cout << "Yes" << endl;
            for (int t : done) cout << t << " ";
            cout << endl;
        }
    }

    return 0;
}