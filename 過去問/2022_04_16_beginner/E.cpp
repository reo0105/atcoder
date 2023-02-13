#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p;
#define INF 1L<<58

int main()
{
    int n, k;
    int ans = 0;
    vector<ll> x(305), y(305);
    // set<p> done0;
    // set<pair<int, int>> done1;
    vector<vector<bool>> done(305, vector<bool>(305, false));

    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> x.at(i) >> y.at(i);

    if (k == 1) {
        cout << "Infinity" << endl;
    } else {
        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                vector<int> identical; 
                if (x.at(i) != x.at(j)) {
                // if (i == j) continue;
                    // double slope = (y.at(j) - y.at(i)) / (x.at(j) - x.at(i));
                    // double b = y.at(i) - (slope * x.at(i));
                    int cnt = 2;
                    if (!done.at(i).at(j)) {
                        identical.push_back(i);
                        identical.push_back(j);
                        for (int l = 0; l < n; l++) {
                            if (l == i || l == j) continue;
                            // double slope0 = (y.at(l) - y.at(i)) / (x.at(l) - x.at(i));
                            if (((ll)(y.at(j) - y.at(i)) * (x.at(l) - x.at(i))) == ((ll)(x.at(j) - x.at(i)) * (y.at(l) - y.at(i)))) {
                                cnt++;
                                identical.push_back(l);
                            }
                        }

                        if (cnt >= k) ans++;
                        for (int i0 = 0; i0 < cnt; i0++) {
                            for (int j0 = i0+1; j0 < cnt; j0++) {
                                done.at(identical.at(i0)).at(identical.at(j0)) = true;
                            }
                        }
                    }
                } else {
                    int cnt = 2;
                    if (!done.at(i).at(j)) {
                        identical.push_back(i);
                        identical.push_back(j);
                        // done1.insert(make_pair(x.at(i), INF));
                        for (int l = 0; l < n; l++) {
                            if (l == i || l == j) continue;
                            if (x.at(i) == x.at(l)) {
                                cnt++;
                                identical.push_back(l);
                            }
                        }

                        if (cnt >= k) ans++;
                        for (int i0 = 0; i0 < cnt; i0++) {
                            for (int j0 = i0+1; j0 < cnt; j0++) {
                                done.at(identical.at(i0)).at(identical.at(j0)) = true;
                            }
                        }
                    }
                }
            }
        }
        cout << ans << endl;
    }


    return 0;
}