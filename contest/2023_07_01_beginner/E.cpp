#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int mex(int x, int y, int z)
{
    for (int i = 0; i <= 3; i++) {
        if (x != i && y != i && z != i) {
            return i;
        }
    }

    return 0;
}


int main()
{
    int n;
    vector<int> a(200005);
    string s;

    cin >> n;
    for (int i = 0; i < n; i++) cin >> a.at(i);
    cin >> s;

    vector<vector<ll>> summ(200005, vector<ll>(3, 0));
    vector<vector<ll>> sumx(200005, vector<ll>(3, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            summ.at(i+1).at(j) = summ.at(i).at(j);
        }
        if (s.at(i)=='M') summ.at(i+1).at(a.at(i))++;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            sumx.at(i+1).at(j) = sumx.at(i).at(j);
        }
        if (s.at(i)=='X') sumx.at(i+1).at(a.at(i))++;
    }

    ll ans = 0;
    vector<ll> cntm(3), cntx(3);
    for (int i = 0; i < n; i++) {
        if (s.at(i) == 'E') {
            for (int j = 0; j < 3; j++) {
                cntm.at(j) = summ.at(i+1).at(j);
                cntx.at(j) = sumx.at(n).at(j) - sumx.at(i+1).at(j);
            }
            // for (int j = 0; j < 3; j++) cout << cntm.at(j) << " ";
            // cout << endl;
            // for (int j = 0; j < 3; j++) cout << cntx.at(j) << " ";
            // cout << endl;

            // if (a.at(i) == 0) {
            //     ans += cntm.at(0) * cntx.at(0) + cntm.at(0) * cntx.at(2) + cntm.at(2) * cntx.at(0) + cntm.at(2) * cntx.at(2); //1
            //     ans += 2 * (cntm.at(1) * cntx.at(0) + cntm.at(0) * cntx.at(1) + cntm.at(1) * cntx.at(1)); //2
            //     ans += 3 * (cntm.at(1) * cntx.at(2) + cntm.at(2) * cntx.at(1)); // 3
            // } else if (a.at(i) == 1) {
            //     ans += 2 * (cntm.at(0) * cntx.at(0) + cntm.at(1) * cntx.at(0) + cntm.at(0) * cntx.at(1)); //2
            //     ans += 3 * (cntm.at(0) * cntx.at(2) + cntm.at(2) * cntx.at(0)); //3
            // } else if (a.at(i) == 2) {
            //     ans += cntm.at(0) * cntx.at(0) + cntm.at(0) * cntx.at(2) + cntm.at(2) * cntx.at(0); //1
            //     ans += 3 * (cntm.at(1) * cntx.at(0) + cntm.at(0) * cntx.at(1)); //3
            // }

            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    ans += cntm.at(j) * cntx.at(k) * mex(a.at(i), j, k);
                }
            }
        } 
    }
    cout << ans << endl;

    return 0; 
}