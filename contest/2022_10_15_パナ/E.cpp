#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pi;

struct edge {
    int to;
    int val;
    edge(int to, int val) : to(to), val(val) {}
};

int main()
{
    int q;
    cin >> q;

    vector<edge> t;
    unordered_map<int, int> mp;
    t.push_back(edge(0, -1));
    int now = 0;


    for (int i = 0; i < q; i++) {
        string s;
        cin >> s;
        if (s == "DELETE") {
            now = t.at(now).to;
        } else {
            int x;
            cin >> x;
            if (s == "ADD") {
                int sz = t.size();
                t.push_back(edge(now, x));
                now = sz;
            } else if (s == "SAVE") {
                mp[x] = now;
            } else {
                now = mp[x];
            }
        }
        cout << t.at(now).val << " ";
    }
    cout << endl;
    
    return 0;
}