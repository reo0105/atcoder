#include <bits/stdc++.h>
using namespace std;
typedef pair<char, int> P;

int main()
{
    int n;
    vector<int> p(405);

    cin >> n;
    for (int i = 1; i <= n; i++) cin >> p.at(i);

    vector<P> ans;

    int id = 1;
    while (id <= n && p.at(id) % 2 == 0) id += 2;
    for (int i = id; i <= n; i+=2) {
        if (p.at(i) % 2 == 0) {
            for (int j = i-2; j >= id; j -= 2) {
                ans.push_back(make_pair('B', j));
                swap(p.at(j), p.at(j+2));
            }
            id += 2;
        }
    }

    id = 2;
    while (id <= n && p.at(id) % 2 == 1) id += 2;
    for (int i = id; i <= n; i+=2) {
        if (p.at(i) % 2 == 1) {
            for (int j = i-2; j >= id; j -= 2) {
                ans.push_back(make_pair('B', j));
                swap(p.at(j), p.at(j+2));
            }
            id += 2;
        }
    }

    for (int i = 1; i <= n-1; i += 2) {
        if (p.at(i) % 2 == 0) {
            ans.push_back(make_pair('A', i));
            swap(p.at(i), p.at(i+1));
        }
    }

    // for (int i = 1; i <= n; i++) cout << p.at(i) << " ";
    // cout << endl;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n-2; j+=2) {
            if (p.at(j) > p.at(j+2)) {
                ans.push_back(make_pair('B', j));
                swap(p.at(j), p.at(j+2));
            }
        } 
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 2; j <= n-2; j+=2) {
            if (p.at(j) > p.at(j+2)) {
                ans.push_back(make_pair('B', j));
                swap(p.at(j), p.at(j+2));
            }
        } 
    }

    n = (int)ans.size();
    cout << n << endl;
    for (int i = 0; i < n; i++) cout << ans.at(i).first << " " << ans.at(i).second << endl;

    return 0;
}
