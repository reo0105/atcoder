#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    vector<vector<int>> G(200005);
    vector<int> p(200005);

    cin >> n;
    for (int i = 0; i < n; i++) cin >> p.at(i);
    for (int i = 0; i < n; i++) {
        int q;
        cin >> q;
        G.at(p.at(i)).push_back(q);
        G.at(q).push_back(p.at(i));
    }

    

}